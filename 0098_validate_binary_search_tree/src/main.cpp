#include <gtest/gtest.h>
#include <limits>
#include <memory>
#include <vector>

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
    [[maybe_unused]] std::vector<int> values = {2, 1, 3};
    auto left = std::make_unique<TreeNode>(1);
    auto right = std::make_unique<TreeNode>(3);
    auto root = std::make_unique<TreeNode>(2, left.get(), right.get());
    ASSERT_TRUE(Solution::isValidBST(root.get()));
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
}
