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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* tail = head;
        int len = 0;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        len+=1;
        int n2 = k%len;
        if(n2==0) return head;
        // cout<<n2<<endl;
        tail->next=head;
        n2 = len-n2;
        while(n2--){
            tail = head;
            head=head->next;
        }
        tail->next = NULL;
        return head;

    }
};