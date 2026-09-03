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
#define node ListNode
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head; 
        node* left=head;
        node* right=head->next;
        while(right){
            bool flag=0;
            while(right && left->val==right->val){
                right->val=-101;
                right=right->next;
                flag=1;
            }
            if(flag){
                left->val=-101;
                if(!right) break;
                left=right;
                right=right->next;
            }
            else{
                left=left->next;
                right=right->next;
            }
        }
        left=new node(-101);
        node* res=left;
        right=head;
        while(right){
            while(right && right->val==-101){
                right=right->next;
            }
            left->next=right;
            if(left) left=left->next;
            if(right) right=right->next;
        }
        return res->next;
    }
};