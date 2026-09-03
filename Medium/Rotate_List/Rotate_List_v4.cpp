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
    int len(ListNode *head){
        int tmp = 0 ;
        while(head!=NULL){
            tmp++;
            head=head->next;
        }
        return tmp;
    }
    void rotate(ListNode* &head){
        ListNode* tail = NULL;
        ListNode* tmp = head;
        ListNode* prev_tail = NULL;
        while(tmp->next!=NULL){
            prev_tail = tmp;
            tmp=tmp->next;
        }
        tail=tmp;
        tail->next=head;
        prev_tail->next = NULL;
        head = tail;
        // return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n = len(head);
        int n2 = k%n;
        if(n2==0) return head;
        cout<<n2<<endl;
        for(int i=0;i<n2;i++){
            rotate(head);
        }
        return head;
    }
};