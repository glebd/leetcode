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
    static void traverse(TreeNode* left, TreeNode* right, std::vector<std::vector<int>>& values, int const level)
    {
        std::vector<int> level_values;
        if (left != nullptr)
            level_values.push_back(left->val);
        if (right != nullptr)
            level_values.push_back(right->val);
        if (!level_values.empty())
        {
            if (level >= values.size())
                values.push_back(level_values);
            else
                values[level].insert(values[level].end(), level_values.begin(), level_values.end());
        }
        if (left != nullptr)
            traverse(left->left, left->right, values, level + 1);
        if (right != nullptr)
            traverse(right->left, right->right, values, level + 1);
    }

    static std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> values;
        if (root == nullptr)
            return values;
        values.push_back({root->val});
        int level = 1;
        traverse(root->left, root->right, values, level);
        return values;
    }
};

TEST(BinTreeTraversal, Test1)
{
    std::vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    std::vector<std::vector<int>> expected = {{3}, {9, 20}, {15, 7}};
    auto l3left = std::make_unique<TreeNode>(15);
    auto l3right = std::make_unique<TreeNode>(7);
    auto l2left = std::make_unique<TreeNode>(9);
    auto l2right = std::make_unique<TreeNode>(20, l3left.get(), l3right.get());
    auto root = std::make_unique<TreeNode>(3, l2left.get(), l2right.get());
    auto actual = Solution::levelOrder(root.get());
    ASSERT_EQ(actual, expected);
}

TEST(BinTreeTraversal, Test2)
{
    std::vector<int> nodes = {1};
    std::vector<std::vector<int>> expected = {{1}};
    auto root = std::make_unique<TreeNode>(1);
    auto actual = Solution::levelOrder(root.get());
    ASSERT_EQ(actual, expected);
}

TEST(BinTreeTraversal, Test4)
{
    std::vector<int> nodes = {1, 2, 3, 4, -1, -1, 5};
    std::vector<std::vector<int>> expected = {{1}, {2, 3}, {4, 5}};
    auto l3leftleft = std::make_unique<TreeNode>(4);
    auto l3rightright = std::make_unique<TreeNode>(5);
    auto l2left = std::make_unique<TreeNode>(2, l3leftleft.get(), nullptr);
    auto l2right = std::make_unique<TreeNode>(3, nullptr, l3rightright.get());
    auto root = std::make_unique<TreeNode>(1, l2left.get(), l2right.get());
    auto actual = Solution::levelOrder(root.get());
    ASSERT_EQ(actual, expected);
}

TEST(BinTreeTraversal, TestEmpty)
{
    std::vector<std::vector<int>> expected = {};
    auto actual = Solution::levelOrder(nullptr);
    ASSERT_EQ(actual, expected);
}
