#ifndef LEETCODE_BINARY_TREE_H
#define LEETCODE_BINARY_TREE_H

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

namespace binary_tree
{
auto values2nodes(const std::vector<int>& values) -> std::vector<std::vector<std::unique_ptr<TreeNode>>>;
auto nodes2root(const std::vector<std::vector<std::unique_ptr<TreeNode>>>& nodes) -> TreeNode*;
} // namespace binary_tree

#endif
