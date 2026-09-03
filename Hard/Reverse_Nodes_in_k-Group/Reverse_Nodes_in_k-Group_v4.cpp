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
        int size = 0;
        while(head){
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* reversehelp(ListNode* head,int k,int size){
        if(size<k) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int cnt = 0;
        while(cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        head->next = reversehelp(curr,k,size-k);
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reversehelp(head,k,len(head));
    }
};