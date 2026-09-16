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
class Solution {
public:
    ListNode* reverse(ListNode* head2)
    {
        ListNode* pre = NULL;
        ListNode* curr = head2;

        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;

        }

        return pre;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
        return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverse(slow);
        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        
        ListNode* ns1;
        ListNode* ns2;
        while(temp2 && temp2->next)
        {
            ns1 = temp1->next;
            ns2 = temp2->next;

            temp1->next = temp2;
            temp2->next = ns1;

            temp1 = ns1;
            temp2 = ns2;
        }

    }
};