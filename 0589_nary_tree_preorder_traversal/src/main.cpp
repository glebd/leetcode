#include <gtest/gtest.h>

#include <algorithm>
#include <memory>
#include <vector>

//
// *** FROM LEETCODE ***
//
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
//

// Definition for a Node.
struct Node
{
    int val{};
    std::vector<Node*> children{};

    Node() = default;

    explicit Node(int _val) : val(_val)
    {
    }

    Node(int _val, std::vector<Node*> _children) : val(_val), children(std::move(_children))
    {
    }
};

class Solution
{
public:
    static std::vector<int> preorder(Node* root)
    {
        return {};
    }
};

//
// *** HELPER FUNCTIONS ***
//

auto value2node(const int value)
{
    return std::make_unique<Node>(value);
}

auto values2nodes(const std::vector<int>& values)
{
    std::vector<std::vector<std::unique_ptr<Node>>> all_nodes;
    int level = 0;// tree level we're currently processing
    std::vector<std::unique_ptr<Node>> cur_level_nodes;
    int parent_index = -1;// index of up-level node to add children to
    for (const int value: values)
    {
        // 1st value of -1 increments depth, but only if the current level is not empty
        // otherwise it skips to the next up-level node's children
        if (value != -1 /*&& !cur_level_nodes.empty()*/)
        {
            // add node with this value to current level nodes
            cur_level_nodes.emplace_back(value2node(value));
            if (parent_index > -1)
            {
                auto& parent_node = all_nodes[level - 1][parent_index];
                auto& node = cur_level_nodes.back();
                parent_node->children.push_back(node.get());
            }
        }
        else
        {
            // check that we're at level 0
            // check that we haven't run out of parent nodes
            ++parent_index;
            if (level == 0 || parent_index >= all_nodes[level - 1].size())// ran out of parents
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
    }

    if (!cur_level_nodes.empty())
    {
        all_nodes.emplace_back(std::move(cur_level_nodes));
    }

    return all_nodes;
}

//
// *** TESTS ***
//

TEST(Tree, Test1)
{
    //               ┌───┐
    //        ┌──────│ 1 │──────┐
    //        │      └───┘      │
    //        │        │        │
    //        ▼        ▼        ▼
    //      ┌───┐    ┌───┐    ┌───┐
    //   ┌──│ 3 │──┐ │ 2 │    │ 4 │
    //   │  └───┘  │ └───┘    └───┘
    //   │         │
    //   ▼         ▼
    // ┌───┐     ┌───┐
    // │ 5 │     │ 6 │
    // └───┘     └───┘

    // -1 means <null> in test data, as node value is 0 <= val <= 10^4
    std::vector<int> tree{1, -1, 3, 2, 4, -1, 5, 6};
    auto nodes = values2nodes(tree);
    std::vector<int> expected{1, 3, 5, 6, 2, 4};
    auto actual = Solution::preorder(nullptr);
    ASSERT_EQ(actual, expected);
}

TEST(Tree, Test2)
{
    //                    ┌───┐
    //   ┌───────────┬────│ 1 │────┬───────────┐
    //   │           │    └───┘    │           │
    //   │           │             │           │
    //   ▼           ▼             ▼           ▼
    // ┌───┐       ┌───┐         ┌───┐       ┌───┐
    // │ 2 │     ┌─│ 3 │─┐       │ 4 │     ┌─│ 5 │─┐
    // └───┘     │ └───┘ │       └───┘     │ └───┘ │
    //           │       │         │       │       │
    //           ▼       ▼         ▼       ▼       ▼
    //         ┌───┐   ┌───┐     ┌───┐   ┌───┐   ┌───┐
    //         │ 6 │   │ 7 │     │ 8 │   │ 9 │   │10 │
    //         └───┘   └───┘     └───┘   └───┘   └───┘
    //                   │         │       │
    //                   ▼         ▼       ▼
    //                 ┌───┐     ┌───┐   ┌───┐
    //                 │11 │     │12 │   │13 │
    //                 └───┘     └───┘   └───┘
    //                   │
    //                   ▼
    //                 ┌───┐
    //                 │14 │
    //                 └───┘

    // -1 means <null> in test data, as node value is 0 <= val <= 10^4
    std::vector<int> tree{1, -1, 2, 3, 4, 5, -1, -1, 6, 7, -1, 8, -1, 9, 10, -1, -1, 11, -1, 12, -1, 13, -1, -1, 14};
    std::vector<int> expected{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
    auto actual = Solution::preorder(nullptr);
    ASSERT_EQ(actual, expected);
}

TEST(Tree, Empty)
{
    ASSERT_EQ(Solution::preorder(nullptr), std::vector<int>{});
}
