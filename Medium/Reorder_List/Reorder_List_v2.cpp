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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        while(head2){
            ListNode* tmp=head2->next;
            head2->next=prev;
            prev=head2;
            head2=tmp;
        }
        ListNode* second=prev;
        ListNode* first=head;
        while(second){
            ListNode* tmp1=first->next;
            ListNode* tmp2=second->next;
            first->next=second;
            second->next=tmp1;
            first=tmp1;
            second=tmp2;
        }
    }
};