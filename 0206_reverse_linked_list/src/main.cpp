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
        ListNode* reversed = nullptr;
        while (head != nullptr)
        {
            ListNode* next = head->next;
            ListNode* reversed_next = reversed;
            reversed = head;
            reversed->next = reversed_next;
            head = next;
        }
        return reversed;
    }

    static ListNode* reverseListRecursive(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* tail = head->next;
        ListNode* rhead = reverseListRecursive(tail);
        tail->next = head;
        head->next = nullptr;
        return rhead;
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

TEST(ReverseLinkedListRecursive, Test1)
{
    std::vector<int> src{1, 2, 3, 4, 5};
    auto list = values2list(src);
    ListNode* head = list.front().get();
    ListNode* reversed = Solution::reverseListRecursive(head);
    ASSERT_NE(head, nullptr);
    auto actual = list2values(reversed);
    std::vector<int> expected{5, 4, 3, 2, 1};
    ASSERT_EQ(actual, expected);
}

TEST(ReverseLinkedListRecursive, Test2)
{
    std::vector<int> src{1, 2};
    auto list = values2list(src);
    ListNode* head = list.front().get();
    ListNode* reversed = Solution::reverseListRecursive(head);
    ASSERT_NE(head, nullptr);
    auto actual = list2values(reversed);
    std::vector<int> expected{2, 1};
    ASSERT_EQ(actual, expected);
}

TEST(ReverseLinkedListRecursive, TestEmpty)
{
    ListNode* reversed = Solution::reverseListRecursive(nullptr);
    ASSERT_EQ(reversed, nullptr);
}
