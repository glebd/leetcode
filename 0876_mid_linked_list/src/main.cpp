#include <gtest/gtest.h>

#include <vector>

// PR: https://github.com/glebd/leetcode/pull/new/0876_mid_linked_list

// Definition for singly-linked list.
struct ListNode
{
    int val{0};
    ListNode* next{nullptr};
    ListNode() = default;
    ListNode(int x) : val(x)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        auto* last = head;
        auto* mid = head;
        while (last)
        {
            last = last->next;
            if (last)
            {
                last = last->next;
                mid = mid->next;
            }
        }

        return mid;
    }
};

/*
std::vector<ListNode*> vector2list(const std::vector<int>& vec)
{
    return nullptr;
}
 */

TEST(MidLinkedList, TestNull)
{
    Solution solution;
    auto* actual = solution.middleNode(nullptr);
    ASSERT_EQ(actual, nullptr);
}

TEST(MidLinkedList, Test1)
{
    //std::vector data = {1, 2, 3, 4, 5};
    auto* elem5 = new ListNode(5);
    auto* elem4 = new ListNode(4, elem5);
    auto* elem3 = new ListNode(3, elem4);
    auto* elem2 = new ListNode(2, elem3);
    auto* head = new ListNode(1, elem2);
    Solution solution;
    auto* actual = solution.middleNode(head);
    ASSERT_EQ(actual, elem3);
}

TEST(MidLinkedList, Test2)
{
    auto* elem6 = new ListNode(6);
    auto* elem5 = new ListNode(5, elem6);
    auto* elem4 = new ListNode(4, elem5);
    auto* elem3 = new ListNode(3, elem4);
    auto* elem2 = new ListNode(2, elem3);
    auto* head = new ListNode(1, elem2);
    Solution solution;
    auto* actual = solution.middleNode(head);
    ASSERT_EQ(actual, elem4);
}

TEST(MidLinkedList, Test3)
{
    auto* head = new ListNode(1);
    Solution solution;
    auto* actual = solution.middleNode(head);
    ASSERT_EQ(actual, head);
}
