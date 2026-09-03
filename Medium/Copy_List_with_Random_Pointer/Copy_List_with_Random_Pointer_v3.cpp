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
        unordered_map<Node*,Node*>old_to_new;
        Node* tmp=head;
        //for each original node made a new node for it
        while(tmp){
            old_to_new[tmp]=new Node(tmp->val);
            tmp=tmp->next;
        }
        tmp=head;
        //add pointer for the new nodes
        while(tmp){
            old_to_new[tmp]->next=old_to_new[tmp->next];
            old_to_new[tmp]->random=old_to_new[tmp->random];
            tmp=tmp->next;
        }
        return old_to_new[head];
    }
};