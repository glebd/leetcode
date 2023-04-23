#include <gtest/gtest.h>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        return {};
    }
};

TEST(BinTreeTraversal, Test1)
{
    ASSERT_TRUE(true);
}
