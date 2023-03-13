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

class Solution
{
public:
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* merged = nullptr;
        ListNode* cur_merged = nullptr;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        do
        {
            if (cur2->val >= cur1->val)
            {
                if (merged == nullptr)
                    merged = cur1;
                if (cur_merged != nullptr)
                    cur_merged->next = cur1;
                cur_merged = cur1;
                cur1 = cur1->next;
            }
            else
            {
                if (merged == nullptr)
                    merged = cur2;
                if (cur_merged != nullptr)
                    cur_merged->next = cur2;
                cur_merged = cur2;
                cur2 = cur2->next;
            }
        } while (cur1 != nullptr && cur2 != nullptr);

        if (cur1 == nullptr)
            cur_merged->next = cur2;
        else
            cur_merged->next = cur1;

        return merged;
    }
};

TEST(MergeSortedLists, Test1)
{
    using namespace testing;

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

    std::vector<int> expected = {1,1,2,3,4,4};
    auto* merged = Solution::mergeTwoLists(list1, list2);

    ASSERT_TRUE(merged != nullptr);
    std::vector<int> actual;
    while (merged)
    {
        actual.push_back(merged->val);
        merged = merged->next;
    }
    ASSERT_EQ(actual, expected);
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

TEST(MergeSortedLists, Fail1)
{
    // ERROR: time limit exceeded
    //[-10,-9,-6,-4,1,9,9]
    auto list1node7 = std::make_unique<ListNode>(-10);
    auto list1node6 = std::make_unique<ListNode>(-9, list1node7.get());
    auto list1node5 = std::make_unique<ListNode>(-6, list1node6.get());
    auto list1node4 = std::make_unique<ListNode>(-4, list1node5.get());
    auto list1node3 = std::make_unique<ListNode>(1, list1node4.get());
    auto list1node2 = std::make_unique<ListNode>(9, list1node3.get());
    auto list1node1 = std::make_unique<ListNode>(9, list1node2.get());
    //[-5,-3,0,7,8,8]
    auto list2node6 = std::make_unique<ListNode>(-5);
    auto list2node5 = std::make_unique<ListNode>(-3, list2node6.get());
    auto list2node4 = std::make_unique<ListNode>(0, list2node5.get());
    auto list2node3 = std::make_unique<ListNode>(7, list2node4.get());
    auto list2node2 = std::make_unique<ListNode>(8, list2node3.get());
    auto list2node1 = std::make_unique<ListNode>(8, list2node2.get());

    std::vector<int> expected = {-10,-9,-6,-5,-4,-3,0,1,7,8,8,9,9};
    auto* merged = Solution::mergeTwoLists(list1node1.get(), list2node1.get());
    ASSERT_NE(merged, nullptr);
    std::vector<int> actual;
    while (merged)
    {
        actual.push_back(merged->val);
        merged = merged->next;
    }
    ASSERT_EQ(actual, expected);
}
