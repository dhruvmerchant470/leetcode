/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node* tmp=head;
       Node* next=head;
       while(tmp){
            next=tmp->next;
            Node* tmp2=new Node(tmp->val);
            tmp2->next=next;
            tmp->next=tmp2;
            tmp=next;
       } 
       tmp=head;
       while(tmp){
        if(tmp->random){
            tmp->next->random=tmp->random->next;
        }
        tmp=tmp->next->next;
       }
       Node* dummy=new Node(0);
       Node* copy,*copy1=dummy;
       tmp=head;
       while(tmp){
        next=tmp->next->next;
        copy=tmp->next;
        copy1->next=copy;
        copy1=copy;
        tmp->next=next;
        tmp=next;
       }
       return dummy->next;
    }
};