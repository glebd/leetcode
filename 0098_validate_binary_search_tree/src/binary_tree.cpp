#include "binary_tree.h"

#include <memory>
#include <vector>

namespace binary_tree
{
static auto value2node(const int value)
{
    return std::make_unique<TreeNode>(value);
}

auto values2nodes(const std::vector<int>& values) -> std::vector<std::vector<std::unique_ptr<TreeNode>>>
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
