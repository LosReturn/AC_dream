/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *temp = dummy;
        ListNode *node1 = dummy->next;
        ListNode *node2 = dummy->next->next;
        while (node1 && node2)
        {
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
            node1 = temp->next;
            node2 = node1->next;
        }
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }
};
// @lc code=end
