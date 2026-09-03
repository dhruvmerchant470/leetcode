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
        Node* tmp = head;
        while (tmp) {
            Node* next = tmp->next;
            Node* n1 = new Node(tmp->val);
            tmp->next = n1;
            n1->next = next;
            tmp = next;
        }
        tmp = head;
        while (tmp) {
            
            if (tmp->random)
                tmp->next->random = tmp->random->next;
            tmp = tmp->next->next;
        }

        tmp = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        Node* copy2 = dummy;
        while (tmp) {
            Node* next = tmp->next->next;
            copy = tmp->next;
            copy2->next = copy;
            copy2=copy;
            tmp->next = next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
};