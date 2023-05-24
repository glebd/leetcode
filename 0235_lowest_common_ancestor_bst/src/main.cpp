#include <gtest/gtest.h>
#include <tools/binary_tree.h>
#include <vector>

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution
{
public:
    /// Find path to the node in BST
    /// \param root BST root node
    /// \param node Node to search for
    /// \return Vector of nodes from root (incl.) to the node (incl.)
    static std::vector<TreeNode*> findPath(TreeNode* root, TreeNode* node)
    {
        std::vector<TreeNode*> path;
        TreeNode* cur = root;
        do {
            path.push_back(cur);
            if (node == root)
                return path;
            if (node->val < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        } while (cur->val != node->val);
        path.push_back(cur);
        return path;
    }

    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        auto p_path = findPath(root, p);
        auto q_path = findPath(root, q);
        size_t index = 0;
        const size_t max_size = std::min(p_path.size(), q_path.size());
        while (index < max_size && p_path[index] == q_path[index])
        {
            ++index;
        }
        return p_path[index - 1]; // last matching index
    }
};

struct SolutionRec
{
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) // NOLINT: misc-no-recursion
    {
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};

struct SolutionIter
{
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) // NOLINT: misc-no-recursion
    {
        while (root)
        {
            if (p->val > root->val && q->val > root->val)
                root = root->right;
            else if (p->val < root->val && q->val < root->val)
                root = root->left;
            else
                return root;
        }
        return nullptr;
    }
};

TEST(CommonAncestor, Test1)
{
    using namespace binary_tree;
    std::vector<int> values = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    ASSERT_EQ(Solution::lowestCommonAncestor(root, p, q), root);
    ASSERT_EQ(SolutionRec::lowestCommonAncestor(root, p, q), root);
    ASSERT_EQ(SolutionIter::lowestCommonAncestor(root, p, q), root);
}

TEST(CommonAncestor, Test2)
{
    using namespace binary_tree;
    std::vector<int> values = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    TreeNode* p = root->left;
    TreeNode* q = p->right;
    ASSERT_EQ(Solution::lowestCommonAncestor(root, p, q), p);
    ASSERT_EQ(SolutionRec::lowestCommonAncestor(root, p, q), p);
    ASSERT_EQ(SolutionIter::lowestCommonAncestor(root, p, q), p);
}

TEST(CommonAncestor, Test3)
{
    using namespace binary_tree;
    std::vector<int> values = {2, 1};
    auto nodes = values2nodes(values);
    TreeNode* root = nodes2root(nodes);
    TreeNode* p = root;
    TreeNode* q = p->left;
    ASSERT_EQ(Solution::lowestCommonAncestor(root, p, q), root);
    ASSERT_EQ(SolutionRec::lowestCommonAncestor(root, p, q), root);
    ASSERT_EQ(SolutionIter::lowestCommonAncestor(root, p, q), root);
}
