/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;

        while(pa!=pb)
        {
            pa = pa? pa->next : headB;
            pb = pa? pb->next : headA;
        }

        return pa;
    }

    //diff
    // a b c d e f
    // d h z s a b c 
    // align right
    ListNode *getIntersectionNodeByDiff(ListNode *headA, ListNode *headB) {
        
        ListNode* pa = headA;
        ListNode* pb = headB;
        
        int lena =0, lenb=0;

        while( pa)
        {
            pa = pa->next;
            lena++;
        }
        while( pb)
        {
            pb = pb->next;
            lenb++;
        }
        pa = headA;
        pb = headB;

        int diff = lena - lenb;
        if(diff<0)
        {    
            std::swap(pa,pb);
            diff = -diff;
        }
        for(int i = 0; i < diff; i++)
            pa = pa->next;

        while( pa!= pb)
        {
            pa = pa -> next;
            pb = pb ->next;
        }

        return pa;
    }
};