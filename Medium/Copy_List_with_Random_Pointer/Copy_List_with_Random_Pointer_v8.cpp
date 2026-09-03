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
        map<Node*,Node*>mp;
        Node* t1 = head;
        while(t1!=NULL){
            Node* n1 = new Node(t1->val);
            mp[t1]=n1;
            t1 = t1->next; 
        }
        Node* t2 = head;
        while(t2!=NULL){
            mp[t2]->next = mp[t2->next];
            mp[t2]->random = mp[t2->random];
            t2 = t2->next;
        }
        return mp[head];
    }
};