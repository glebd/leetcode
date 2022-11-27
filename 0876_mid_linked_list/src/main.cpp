#include <gtest/gtest.h>

#include <memory>

// PR: https://github.com/glebd/leetcode/pull/new/0876_mid_linked_list

// Definition for singly-linked list.
struct ListNode
{
    int val{0};
    ListNode* next{nullptr};
    ListNode() = default;
    explicit ListNode(int x) : val(x)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    static ListNode* middleNode(ListNode* head)
    {
        auto* last = head;
        auto* mid = head;
        while (last && last->next)
        {
            last = last->next->next;
            mid = mid->next;
        }

        return mid;
    }
};

TEST(MidLinkedList, TestNull)
{
    auto* actual = Solution::middleNode(nullptr);
    ASSERT_EQ(actual, nullptr);
}

TEST(MidLinkedList, Test1)
{
    auto elem5 = std::make_unique<ListNode>(5);
    auto elem4 = std::make_unique<ListNode>(4, elem5.get());
    auto elem3 = std::make_unique<ListNode>(3, elem4.get());
    auto elem2 = std::make_unique<ListNode>(2, elem3.get());
    auto head = std::make_unique<ListNode>(1, elem2.get());
    Solution solution;
    auto* actual = Solution::middleNode(head.get());
    ASSERT_EQ(actual, elem3.get());
}

TEST(MidLinkedList, Test2)
{
    auto elem6 = std::make_unique<ListNode>(6);
    auto elem5 = std::make_unique<ListNode>(5, elem6.get());
    auto elem4 = std::make_unique<ListNode>(4, elem5.get());
    auto elem3 = std::make_unique<ListNode>(3, elem4.get());
    auto elem2 = std::make_unique<ListNode>(2, elem3.get());
    auto head = std::make_unique<ListNode>(1, elem2.get());
    auto* actual = Solution::middleNode(head.get());
    ASSERT_EQ(actual, elem4.get());
}

TEST(MidLinkedList, Test3)
{
    auto head = std::make_unique<ListNode>(1);
    auto* actual = Solution::middleNode(head.get());
    ASSERT_EQ(actual, head.get());
}
