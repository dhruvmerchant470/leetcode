/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,char>mp;
        while(headA){
            mp[headA]='a';
            headA=headA->next;
        }
        while(headB){
            if(mp[headB]=='a') return headB;
            headB=headB->next;
        }
        return NULL;
    }
};