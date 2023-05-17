#include <gtest/gtest.h>
#include <limits>
#include <memory>
#include <vector>

// https://leetcode.com/problems/validate-binary-search-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val{0};
    TreeNode* left{};
    TreeNode* right{};
    TreeNode() = default;
    explicit TreeNode(int x) : val(x)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    static bool validate(TreeNode* node, long minBound, long maxBound)
    {
        if (node == nullptr)
            return true;
        auto val = node->val;
        if (val <= minBound || val >= maxBound)
            return false;
        return validate(node->left, minBound, val) && validate(node->right, val, maxBound);
    }

    static bool isValidBST(TreeNode* root)
    {
        return validate(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }
};

class SolutionInOrder
{
public:
    long prev{std::numeric_limits<long>::min()};

    bool inorder(TreeNode* node)
    {
        if (node == nullptr)
            return true;
        if (!inorder(node->left))
            return false;
        auto val = node->val;
        if (val <= prev)
            return false;
        prev = val;
        return inorder(node->right);
    }

    bool isValidBST(TreeNode* root)
    {
        return inorder(root);
    }
};

//
// *** HELPER FUNCTIONS ***
//

namespace binary_tree
{
auto value2node(const int value)
{
    return std::make_unique<TreeNode>(value);
}

auto values2nodes(const std::vector<int>& values)
{
    std::vector<std::vector<std::unique_ptr<TreeNode>>> all_nodes;
    int level = 0; // tree level we're currently processing
    std::vector<std::unique_ptr<TreeNode>> cur_level_nodes;
    int parent_index = -1; // index of up-level node to add children to
    bool left_child = true;
    for (const int value: values)
    {
        // A value of -1 means no child in that position
        if (value != -1)
        {
            // add node with this value to current level nodes
            cur_level_nodes.emplace_back(value2node(value));
            if (parent_index > -1)
            {
                auto& parent_node = all_nodes[level - 1][parent_index];
                auto& node = cur_level_nodes.back();
                if (left_child)
                    parent_node->left = node.get();
                else
                    parent_node->right = node.get();
                left_child = !left_child;
            }
            else
            {
                // root node
                // add current level nodes to all nodes
                all_nodes.emplace_back(std::move(cur_level_nodes));
                // increment current level
                ++level;
                // clear current level nodes
                cur_level_nodes.clear();
                parent_index = 0;
            }
        }
        else
        {
            // check that we're at level 0
            // check that we haven't run out of parent nodes
            ++parent_index;
            if (level == 0 || parent_index >= all_nodes[level - 1].size()) // ran out of parents
            {
                // add current level nodes to all nodes
                all_nodes.emplace_back(std::move(cur_level_nodes));
                // increment current level
                ++level;
                // clear current level nodes
                cur_level_nodes.clear();
                parent_index = 0;
            }
        }
    }

    if (!cur_level_nodes.empty())
    {
        all_nodes.emplace_back(std::move(cur_level_nodes));
    }

    return all_nodes;
}

TreeNode* nodes2root(const std::vector<std::vector<std::unique_ptr<TreeNode>>>& nodes)
{
    if (nodes.empty())
        return nullptr;
    if (nodes[0].empty())
        return nullptr;
    return nodes[0][0].get();
}
} // namespace binary_tree

//        ┌───┐
//   ┌────│ 2 │────┐
//   │    └───┘    │
//   │             │
//   ▼             ▼
// ┌───┐         ┌───┐
// │ 1 │         │ 3 │
// └───┘         └───┘

TEST(ValidateBinarySearchTree, Test1)
{
    using namespace binary_tree;
    [[maybe_unused]] std::vector<int> values = {2, 1, 3};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    ASSERT_TRUE(Solution::isValidBST(root));
    SolutionInOrder solution;
    ASSERT_TRUE(solution.isValidBST(root));
}

//        ┌───┐
//   ┌────│ 5 │────┐
//   │    └───┘    │
//   │             │
//   ▼             ▼
// ┌───┐         ┌───┐
// │ 1 │    ┌────│ 4 │────┐
// └───┘    │    └───┘    │
//          │             │
//          ▼             ▼
//        ┌───┐         ┌───┐
//        │ 3 │         │ 6 │
//        └───┘         └───┘

TEST(ValidateBinarySearchTree, Test2)
{
    [[maybe_unused]] std::vector<int> values = {5, 1, 4, -1, -1, 3, 6};
    auto node3 = std::make_unique<TreeNode>(3);
    auto node6 = std::make_unique<TreeNode>(6);
    auto node4 = std::make_unique<TreeNode>(4, node3.get(), node6.get());
    auto node1 = std::make_unique<TreeNode>(1);
    auto root = std::make_unique<TreeNode>(5, node1.get(), node4.get());
    ASSERT_FALSE(Solution::isValidBST(root.get()));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root.get()));
}

//        ┌───┐
//   ┌────│ 5 │────┐
//   │    └───┘    │
//   │             │
//   ▼             ▼
// ┌───┐         ┌───┐
// │ 4 │    ┌────│ 6 │────┐
// └───┘    │    └───┘    │
//          │             │
//          ▼             ▼
//        ┌───┐         ┌───┐
//        │ 3 │         │ 7 │
//        └───┘         └───┘

TEST(ValidateBinarySearchTree, Test75)
{
    [[maybe_unused]] std::vector<int> values = {5, 4, 6, -1, -1, 3, 7};
    auto node3 = std::make_unique<TreeNode>(3);
    auto node7 = std::make_unique<TreeNode>(7);
    auto node6 = std::make_unique<TreeNode>(6, node3.get(), node7.get());
    auto node4 = std::make_unique<TreeNode>(4);
    auto root = std::make_unique<TreeNode>(5, node4.get(), node6.get());
    ASSERT_FALSE(Solution::isValidBST(root.get()));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root.get()));
}

//           ┌───┐
//        ┌──│32 │──┐
//        │  └───┘  │
//        │         │
//        ▼         ▼
//      ┌───┐     ┌───┐
//   ┌──│26 │     │47 │──┐
//   │  └───┘     └───┘  │
//   │                   │
//   ▼                   ▼
// ┌───┐               ┌───┐
// │19 │──┐            │56 │
// └───┘  │            └───┘
//        │
//        ▼
//      ┌───┐
//      │27 │
//      └───┘

TEST(ValidateBinarySearchTree, Test76)
{
    [[maybe_unused]] std::vector<int> values = {32, 26, 47, 19, -1, -1, 56, -1, 27};
    auto node27 = std::make_unique<TreeNode>(27);
    auto node19 = std::make_unique<TreeNode>(19, nullptr, node27.get());
    auto node56 = std::make_unique<TreeNode>(56);
    auto node26 = std::make_unique<TreeNode>(26, node19.get(), nullptr);
    auto node47 = std::make_unique<TreeNode>(47, nullptr, node56.get());
    auto root = std::make_unique<TreeNode>(32, node26.get(), node47.get());
    ASSERT_FALSE(Solution::isValidBST(root.get()));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root.get()));
}

TEST(ValidateBinarySearchTree, Test80)
{
    [[maybe_unused]] std::vector<int> values = {120, 70, 140, 50, 100, 130, 160, 20, 55, 75, 110, 119, 135, 150, 200};
    // Level 4
    auto node20 = std::make_unique<TreeNode>(20);
    auto node55 = std::make_unique<TreeNode>(55);
    auto node75 = std::make_unique<TreeNode>(75);
    auto node110 = std::make_unique<TreeNode>(110);
    auto node119 = std::make_unique<TreeNode>(119);
    auto node135 = std::make_unique<TreeNode>(135);
    auto node150 = std::make_unique<TreeNode>(150);
    auto node200 = std::make_unique<TreeNode>(200);
    // Level 3
    auto node50 = std::make_unique<TreeNode>(50, node20.get(), node55.get());
    auto node100 = std::make_unique<TreeNode>(100, node75.get(), node110.get());
    auto node130 = std::make_unique<TreeNode>(130, node119.get(), node135.get());
    auto node160 = std::make_unique<TreeNode>(160, node150.get(), node200.get());
    // Level 2
    auto node70 = std::make_unique<TreeNode>(70, node50.get(), node100.get());
    auto node140 = std::make_unique<TreeNode>(140, node130.get(), node160.get());
    // Level 1
    auto root = std::make_unique<TreeNode>(120, node70.get(), node140.get());
    ASSERT_FALSE(Solution::isValidBST(root.get()));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root.get()));
}
