#include <gtest/gtest.h>
#include <limits>
#include <memory>
#include <vector>

#include "binary_tree.h"

// https://leetcode.com/problems/validate-binary-search-tree/

class Solution
{
public:
    static bool validate(TreeNode* node, long minBound, long maxBound) // NOLINT
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

    bool inorder(TreeNode* node) // NOLINT
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
