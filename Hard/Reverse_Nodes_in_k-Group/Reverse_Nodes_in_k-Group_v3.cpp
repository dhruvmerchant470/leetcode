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
    int len(ListNode* head){
        ListNode *tmp=head;
        int cnt=0;
        while(tmp){
            cnt++;
            tmp=tmp->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=len(head);
        ListNode *curr=head;
        ListNode *next=NULL,*prev=NULL;
        int cnt=0;
        while(cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(size-cnt<k){
            head->next=next;
        }
        else{
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};