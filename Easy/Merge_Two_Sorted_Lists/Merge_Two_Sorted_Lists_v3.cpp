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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* tmp=list1;
        if(list1->val<list2->val){
            list1=list1->next;
        }
        else{
            tmp=list2;
            list2=list2->next;
        }
        ListNode *head=tmp;
        while(list1 && list2){
            if(list1->val>list2->val){
                tmp->next=list2;
                tmp=list2;
                list2=list2->next;
            }
            else{
                tmp->next=list1;
                tmp=list1;
                list1=list1->next;
            }
        }
        while(list1){
            tmp->next=list1;
            tmp=list1;
            list1=list1->next;
        }

        while(list2){
            tmp->next=list2;
            tmp=list2;
            list2=list2->next;
        }
        tmp->next=NULL;
        return head;
        
    }
};