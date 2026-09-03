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
    ListNode* partition(ListNode* head, int x) {
        ListNode* t1=new ListNode();
        ListNode* t2=new ListNode();
        ListNode* next=t2;
        ListNode* start=t1;
        ListNode* tmp=head;
        while(tmp){
            if(tmp->val>=x){
                t2->next=tmp;
                t2=tmp;
            }
            else{
                t1->next=tmp;
                t1=tmp;
            }
            tmp=tmp->next;
        }
        t2->next=NULL;
        t1->next=next->next;
        return start->next;
    }
};