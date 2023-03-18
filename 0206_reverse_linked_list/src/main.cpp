#include <gtest/gtest.h>

#include <algorithm>
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
    static ListNode* reverseList(ListNode* head)
    {
        return nullptr;
    }
};

TEST(ReverseLinkedList, Test1)
{
    std::vector<int> src{1, 2, 3, 4, 5};
    auto list = values2list(src);
    ListNode* head = list.front().get();
    ListNode* reversed = Solution::reverseList(head);
    ASSERT_NE(head, nullptr);
    auto actual = list2values(reversed);
    std::vector<int> expected{5, 4, 3, 2, 1};
    ASSERT_EQ(actual, expected);
}

TEST(ReverseLinkedList, Test2)
{
    std::vector<int> src{1, 2};
    auto list = values2list(src);
    ListNode* head = list.front().get();
    ListNode* reversed = Solution::reverseList(head);
    ASSERT_NE(head, nullptr);
    auto actual = list2values(reversed);
    std::vector<int> expected{2, 1};
    ASSERT_EQ(actual, expected);
}

TEST(ReverseLinkedList, TestEmpty)
{
    ListNode* reversed = Solution::reverseList(nullptr);
    ASSERT_EQ(reversed, nullptr);
}
