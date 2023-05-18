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
    int parent_index = 0; // index of up-level node to add children to
    bool left_child = true;
    for (const int value: values)
    {
        // add node with this value to current level nodes
        cur_level_nodes.emplace_back(value2node(value));
        if (level > 0)
        {
            auto& parent_node = all_nodes[level - 1][parent_index];
            auto& node = cur_level_nodes.back();
            if (left_child)
            {
                if (value != -1)
                    parent_node->left = node.get();
            }
            else
            {
                // at the right child
                if (value != -1)
                    parent_node->right = node.get();

                // go to next parent
                ++parent_index;
            }
            left_child = !left_child;
        }

        // check that we're either on level 0 or that we ran out of parent nodes, and if so, go to next level
        if (level == 0 || parent_index >= static_cast<int>(all_nodes[level - 1].size()))
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
    std::vector<int> values = {2, 1, 3};
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
    using namespace binary_tree;
    std::vector<int> values = {5, 1, 4, -1, -1, 3, 6};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    ASSERT_FALSE(Solution::isValidBST(root));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root));
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
    using namespace binary_tree;
    std::vector<int> values = {5, 4, 6, -1, -1, 3, 7};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    ASSERT_FALSE(Solution::isValidBST(root));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root));
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
    using namespace binary_tree;
    std::vector<int> values = {32, 26, 47, 19, -1, -1, 56, -1, 27};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    ASSERT_FALSE(Solution::isValidBST(root));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root));
}

TEST(ValidateBinarySearchTree, Test80)
{
    using namespace binary_tree;
    std::vector<int> values = {120, 70, 140, 50, 100, 130, 160, 20, 55, 75, 110, 119, 135, 150, 200};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    ASSERT_FALSE(Solution::isValidBST(root));
    SolutionInOrder solution;
    ASSERT_FALSE(solution.isValidBST(root));
}
