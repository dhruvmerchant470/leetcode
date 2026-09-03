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
    int len1(ListNode* head){
        int cnt=0;
        while(head!=NULL) {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        ListNode* prev=NULL;
        int cnt=len1(head);
        int n1=cnt-n;
        if(n1==0) return head->next;
        for(int i=0;i<n1;i++){
            prev=tmp;
            tmp=tmp->next;
        }
        if(prev&&tmp) prev->next=tmp->next;
    return head;
    }
};