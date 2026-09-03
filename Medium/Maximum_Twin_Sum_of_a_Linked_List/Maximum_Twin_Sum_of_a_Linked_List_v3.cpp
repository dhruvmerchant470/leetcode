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

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            ListNode* nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        int ans = INT_MIN;
        while(slow){
            ans = max(ans,slow->val+prev->val);
            prev = prev->next;
            slow = slow->next;
        }
        return ans;
    }
};