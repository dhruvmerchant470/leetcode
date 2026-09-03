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
#define Node ListNode
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        Node* tmp=head->next->next;
        Node* head1=head;
        Node* head2=head->next;
        Node* store=head2;
        Node* res=head1;
        bool flag=1;
        while(tmp){
            if(flag){
                head1->next=tmp;
                head1=tmp;
            }
            else{
                head2->next=tmp;
                head2=tmp;
            }
            tmp=tmp->next;
            flag=!flag;
        }
        head1->next=store;
        head2->next=NULL;
        return res;
    }
};