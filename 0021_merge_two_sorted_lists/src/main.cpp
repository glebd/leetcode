#include <gtest/gtest.h>

#include <memory>
#include <vector>
#include <algorithm>

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
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
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

TEST(MergeSortedLists, Test1)
{
    using namespace testing;

    std::vector<int> list1_values{1, 2, 4};
    auto list1 = values2list(list1_values);
    ListNode* list1_head = list1.front().get();

    std::vector<int> list2_values{1, 3, 4};
    auto list2 = values2list(list2_values);
    ListNode* list2_head = list2.front().get();

    std::vector<int> expected = {1, 1, 2, 3, 4, 4};
    auto* merged = Solution::mergeTwoLists(list1_head, list2_head);

    ASSERT_TRUE(merged != nullptr);
    auto actual = list2values(merged);
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
    //[-10,-9,-6,-4,1,9,9]
    std::vector<int> list1_values{-10, -9, -6, -4, 1, 9, 9};
    auto list1 = values2list(list1_values);
    ListNode* list1_head = list1.front().get();
    //[-5,-3,0,7,8,8]
    std::vector<int> list2_values{-5, -3, 0, 7, 8, 8};
    auto list2 = values2list(list2_values);
    ListNode* list2_head = list2.front().get();

    std::vector<int> expected = {-10, -9, -6, -5, -4, -3, 0, 1, 7, 8, 8, 9, 9};
    auto* merged = Solution::mergeTwoLists(list1_head, list2_head);
    ASSERT_NE(merged, nullptr);
    auto actual = list2values(merged);
    ASSERT_EQ(actual, expected);
}
