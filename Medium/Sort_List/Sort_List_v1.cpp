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
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode *tmp=new ListNode(0);
        ListNode* tmp1=tmp;
        while(left!=NULL && right!=NULL){
            if(left->val>right->val){
                tmp1->next=right;
                right=right->next;
                tmp1=tmp1->next;
            }
            else {
                tmp1->next=left;
                left=left->next;
                tmp1=tmp1->next;
            }
        }
        tmp1->next= left?left:right;
        return tmp->next;
    }
    ListNode* mergeSort(ListNode* start){
        if(start==NULL || start->next==NULL) return start;

        ListNode* slow=start;
        ListNode* fast=start->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* mid=slow->next;
        slow->next=NULL;
        ListNode* left=mergeSort(start);
        ListNode* right=mergeSort(mid);
        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

};