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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void deleteL(ListNode* &head)
    {
        ListNode* tmp=head;
        while(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        ListNode* p=tmp->next;
        tmp->next=NULL;
        delete p;
    }
void insertAtHead(ListNode* &tmp,int data)
{
    ListNode* new1=new ListNode(data);
    new1->next=tmp;
    tmp=new1;
}
void deleteZero(ListNode* &tmp)
{
    ListNode* head=tmp;
    while(head->val==0&&head->next!=NULL)
    {
        ListNode* p=head;
        head=head->next;
        delete p;
    }
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* tmp=new ListNode(0);
        int carry=0;
        while(head1!=NULL&&head2!=NULL)
        {
            long long int sum=head1->val+head2->val+carry;
            carry=sum/10;
            sum=sum%10;
            insertAtHead(tmp,sum);
            head1=head1->next;
            head2=head2->next;
        }
         
         while(head1!=NULL)
        {
            long long int sum=head1->val+carry;
            carry=sum/10;
            sum=sum%10;
            insertAtHead(tmp,sum);
            head1=head1->next;
            
        }
         while(head2!=NULL)
        {
            long long int sum=head2->val+carry;
            carry=sum/10;
            sum=sum%10;
            insertAtHead(tmp,sum);
            
            head2=head2->next;
        }
        while(carry!=0)
        {
            long long int sum=carry;
            carry=sum/10;
            sum=sum%10;
            insertAtHead(tmp,sum);
            
        }
        deleteL(tmp);
        deleteZero(tmp);
        return reverse(tmp);
    }
};