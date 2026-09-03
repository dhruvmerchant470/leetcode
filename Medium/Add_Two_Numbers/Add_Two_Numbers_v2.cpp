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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* next=curr;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void insertAtTail(ListNode* &tail,int data)
    {
        ListNode* newnode=new ListNode(data);
        tail->next=newnode;
        tail=newnode;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=(l1);
        ListNode* head2=(l2);
        ListNode* tmp=new ListNode(-1);
        ListNode* ans=tmp;
        int carry=0;
        while(head1!=NULL&&head2!=NULL)
        {
            int sum=head1->val+head2->val+carry;
            carry=sum/10;
            sum=sum%10;
            head1=head1->next;
            head2=head2->next;
            insertAtTail(tmp,sum);
        }
        while(head1!=NULL)
        {
            int sum=head1->val+carry;
            carry=sum/10;
            sum=sum%10;
            head1=head1->next;
          
            insertAtTail(tmp,sum);
        }
        while(head2!=NULL)
        {
            int sum=head2->val+carry;
            carry=sum/10;
            sum=sum%10;
            
            head2=head2->next;
            insertAtTail(tmp,sum);
        }
        while(carry!=0)
        {
            int sum=carry;
            carry=sum/10;
            sum=sum%10;
            insertAtTail(tmp,sum);
        }
        return ans->next;
    }
};