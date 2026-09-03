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
    while(head!=NULL)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
  }
public:
    void rotate(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        curr->next=head;
        head = curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int k1=k%(len1(head));
        for(int i=0;i<k1;i++)
        {
            rotate(head);
        }
        return head;
    }
};