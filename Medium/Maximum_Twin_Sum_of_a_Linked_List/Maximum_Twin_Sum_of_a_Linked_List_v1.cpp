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
    #define Node ListNode
    ListNode* reverse(ListNode* head){
        Node* curr = head;
        Node* prev=NULL;
        Node* next;
        while(curr){
            ListNode* n  = new Node(curr->val);
            next = curr->next;
            n->next = prev;
            prev = n;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* rev = reverse(head);
        int ans = INT_MIN;
        while(rev){
            ans = max(ans,rev->val+head->val);
            rev = rev->next;
            head = head->next;
        }
        return ans;
    }
};