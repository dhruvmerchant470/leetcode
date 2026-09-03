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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL) return NULL;
        unordered_map<int, ListNode*>map1;
        ListNode* ans=new ListNode(0);
        ans->next=head;
        map1[0]=ans;
        int preSum=0;
        while(head!=NULL){
            preSum+=head->val;
            if(map1.find(preSum)!=map1.end()){
                ListNode* st=map1[preSum];
                int prevSum=preSum;
                while(st!=NULL&&st!=head){
                    st=st->next;
                    prevSum+=st->val;
                    if(st!=head)
                    {
                        map1.erase(prevSum);
                    }
                }
                map1[preSum]->next=st->next;
            }
            else{
                map1[preSum]=head;
            }
            head=head->next;
        }
        return ans->next;
    }
};