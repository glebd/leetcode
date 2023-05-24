#include <gtest/gtest.h>
#include <tools/binary_tree.h>

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return nullptr;
    }
};

TEST(CommonAncestor, Test1)
{
    using namespace binary_tree;
    std::vector<int> values = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    Solution solution;
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    ASSERT_EQ(solution.lowestCommonAncestor(root, p, q), root);
}

TEST(CommonAncestor, Test2)
{
    using namespace binary_tree;
    std::vector<int> values = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    Solution solution;
    TreeNode* p = root->left;
    TreeNode* q = p->right;
    ASSERT_EQ(solution.lowestCommonAncestor(root, p, q), p);
}

TEST(CommonAncestor, Test3)
{
    using namespace binary_tree;
    std::vector<int> values = {2, 1};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    Solution solution;
    TreeNode* p = root;
    TreeNode* q = p->left;
    ASSERT_EQ(solution.lowestCommonAncestor(root, p, q), root);
}
