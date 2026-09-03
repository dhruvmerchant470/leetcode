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
        map<Node*,Node*>old_to_new;
        Node* ptr=head;
        while(ptr){
            old_to_new[ptr]=new Node(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr){
            old_to_new[ptr]->next=old_to_new[ptr->next];
            old_to_new[ptr]->random=old_to_new[ptr->random];
            ptr=ptr->next;
        }
        return old_to_new[head];
    }
};