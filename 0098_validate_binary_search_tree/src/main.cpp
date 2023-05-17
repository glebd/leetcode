#include <gtest/gtest.h>
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
    static bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        if (root->left != nullptr && root->left->val >= root->val)
            return false;
        if (root->right != nullptr && root->right->val <= root->val)
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
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
