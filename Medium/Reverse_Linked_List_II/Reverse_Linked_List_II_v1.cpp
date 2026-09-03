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
        int cnt=0;
        while(head){
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    pair<ListNode*,ListNode*> getNode(ListNode* tmp,int left){
        ListNode* prev;
        for(int i=1;i<left;i++){
            prev=tmp;
            tmp=tmp->next;
        }
        return {prev,tmp};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int len_n=len(head);
        if(left==right) return head;
        if(len_n==1) return head;
        pair<ListNode*,ListNode*> tmp=getNode(head,left);
        int cnt=right-left;
        ListNode* t1=tmp.second;
        ListNode* t2=NULL;
        ListNode* next=NULL;
        for(int i=0;i<=cnt;i++){
            // cout<<"hi"<<endl;
            next=t1->next;
            t1->next=t2;
            t2=t1;
            t1=next;
        }
        if(next) tmp.second->next=next;
        if(tmp.first) tmp.first->next=t2;
        return left==1?t2:head;
    }
};