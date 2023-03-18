#include <gtest/gtest.h>

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

class Solution
{
public:
    static ListNode* reverseList(ListNode* head)
    {
    }
};

TEST(ReverseLinkedList, Test1)
{
    ASSERT_TRUE(true);
}
