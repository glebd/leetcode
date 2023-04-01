#include <algorithm>
#include <gtest/gtest.h>
#include <memory>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr)
    {
    }
    ListNode(int x)
        : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x), next(next)
    {
    }
};

auto values2list(const std::vector<int>& values)
{
    std::vector<std::unique_ptr<ListNode>> list1(values.size());
    std::transform(values.begin(), values.end(), list1.begin(), [](const int value)
                   { return std::make_unique<ListNode>(value); });
    for (int i = 0; i < static_cast<int>(list1.size()) - 1; ++i)
        list1[i]->next = list1[i + 1].get();
    return list1;
}

auto list2values(ListNode* head)
{
    std::vector<int> values;
    while (head)
    {
        values.push_back(head->val);
        head = head->next;
    }
    return values;
}

class Solution
{
public:
    static ListNode* detectCycle(ListNode* head)
    {
        return head;
    }
};

int node2index(const std::vector<std::unique_ptr<ListNode>>& list, const ListNode* node)
{
    int index = -1;
    for (int i = 0; i < static_cast<int>(list.size()); ++i)
    {
        const auto& elem = list[i];
        if (node == elem.get())
        {
            index = i;
            break;
        }
    }
    return index;
}

TEST(LinkedListCycle2, Test1)
{
    std::vector<int> src{3, 2, 0, -4};
    auto list = values2list(src);
    ListNode* head = list.front().get();
    ListNode* cycle = Solution::detectCycle(head);
    int index = node2index(list, cycle);
    ASSERT_EQ(index, 1);
}
