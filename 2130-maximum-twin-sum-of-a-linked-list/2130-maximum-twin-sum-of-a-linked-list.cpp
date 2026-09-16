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
    int pairSum(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = reverse(slow);
        
        int summax = INT_MIN;
        while(head2)
        {
            int sum = head->val + head2->val;
            summax = max(sum,summax);
            head = head->next;
            head2 = head2->next;
        }

        return summax;
        


    }
};