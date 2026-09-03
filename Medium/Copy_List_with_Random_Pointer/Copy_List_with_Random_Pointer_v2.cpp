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
        if(!head) return head;
        Node* org=head;
        Node* tmp=NULL;
        while(org!=NULL){
            tmp=new Node(org->val);
            tmp->next=org->next;
            org->next=tmp;
            org=tmp->next;
        }
        org=head;
        Node* ans=org->next;
        while(org!=NULL){
            if(org->random) org->next->random=org->random->next;
            else org->next->random=NULL;
            org=org->next->next;
        }
        org=head;
        while(org!=NULL){
            tmp=org->next;
            org->next=tmp->next;
            org=org->next;
            if(org) tmp->next=org->next;
            else tmp->next=NULL;
        }
        
        return ans;
    }
};