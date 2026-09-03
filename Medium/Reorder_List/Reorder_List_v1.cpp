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
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* rev(ListNode* &head){
        ListNode* tmp=head;
        ListNode* next=NULL,*prev=NULL;
        while(tmp){
            next=tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* tmp=head;
        ListNode* res=head;
        ListNode* tmp1=head;
        int length=len(head);
        int n=(length+1)/2;
        for(int i=0;i<n-1;i++){
            tmp=tmp->next;
        }
        ListNode* tmp2=tmp->next;
        tmp->next=NULL;
        ListNode* rev1=rev(tmp2);
      
        for(int i=0;i<n;i++){
            ListNode* next=tmp1->next;
            ListNode* next1=NULL;
            if(rev1!=NULL) next1=rev1->next;
            tmp1->next=rev1;
            if(rev1!=NULL) rev1->next=next;
            tmp1=next;
            if(rev1!=NULL) rev1=next1;
        }
        
        head=res;
    }   
};