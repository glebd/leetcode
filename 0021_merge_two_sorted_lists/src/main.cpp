#include <gtest/gtest.h>

#include <memory>

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
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        return nullptr;
    }
};

TEST(MergeSortedLists, Test1)
{
    auto list1node1 = std::make_unique<ListNode>(1);
    auto list1node2 = std::make_unique<ListNode>(2);
    auto list1node3 = std::make_unique<ListNode>(4);
    ListNode* list1 = list1node1.get();
    list1node1->next = list1node2.get();
    list1node2->next = list1node3.get();

    auto list2node1 = std::make_unique<ListNode>(1);
    auto list2node2 = std::make_unique<ListNode>(3);
    auto list2node3 = std::make_unique<ListNode>(4);
    ListNode* list2 = list2node1.get();
    list2node1->next = list2node2.get();
    list2node2->next = list2node3.get();

    auto* merged = Solution::mergeTwoLists(list1, list2);

    ASSERT_TRUE(merged != nullptr);
    ASSERT_EQ(merged, list1node1.get());
    ASSERT_TRUE(merged->next != nullptr);
    ASSERT_EQ(merged->next, list2node1.get());
    ASSERT_TRUE(merged->next->next != nullptr);
    ASSERT_EQ(merged->next->next, list1node2.get());
    ASSERT_TRUE(merged->next->next->next != nullptr);
    ASSERT_EQ(merged->next->next->next, list2node2.get());
    ASSERT_TRUE(merged->next->next->next->next != nullptr);
    ASSERT_EQ(merged->next->next->next->next, list1node3.get());
    ASSERT_TRUE(merged->next->next->next->next->next != nullptr);
    ASSERT_EQ(merged->next->next->next->next->next, list2node3.get());
}

TEST(MergeSortedLists, TestEmpty)
{
    auto* merged = Solution::mergeTwoLists(nullptr, nullptr);
    ASSERT_EQ(merged, nullptr);
}

TEST(MergeSortedLists, TestFirstEmpty)
{
    auto node = std::make_unique<ListNode>(0);
    auto* merged = Solution::mergeTwoLists(nullptr, node.get());
    ASSERT_NE(merged, nullptr);
    ASSERT_EQ(merged, node.get());
}

TEST(MergeSortedLists, TestSecondEmpty)
{
    auto node = std::make_unique<ListNode>(0);
    auto* merged = Solution::mergeTwoLists(node.get(), nullptr);
    ASSERT_NE(merged, nullptr);
    ASSERT_EQ(merged, node.get());
}
