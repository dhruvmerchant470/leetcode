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
private:
int len1(ListNode* head)
{
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;

        //do for first k numbers
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=curr;
        int size=len1(head);
        // cout<<size<<endl;
        int cnt=0;
        while(curr!=NULL && cnt<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        if(next!=NULL&&size-cnt>=k)
        {
            head->next=reverseKGroup(next,k);
        }
        else
        {
            head->next=next;
        }

        return prev;

    }
};