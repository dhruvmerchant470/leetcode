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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        stack<int>s;
        ListNode* slow=head;
        ListNode* fast=head;
        s.push(slow->val);
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            s.push(slow->val);
        }
        s.pop();
        if(fast) slow=slow->next;
        while(slow){
            int val=s.top();
            s.pop();
            if(val!=slow->val) return false;
            slow=slow->next;
        }
        return true;
    }
};