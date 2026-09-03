/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*>old_to_new;
        //do a bfs traversal;
        Node* tmp=new Node(node->val);
        queue<Node*>q;
        q.push(node);
        old_to_new[node]=tmp;
        while(!q.empty()){
            Node* t1=q.front();
            q.pop();
            for(auto nbr:t1->neighbors){
                if(old_to_new.find(nbr)==old_to_new.end()){
                    Node* t2=new Node(nbr->val);
                    old_to_new[nbr]=t2;
                    q.push(nbr);
                }
                old_to_new[t1]->neighbors.push_back(old_to_new[nbr]);
            }
        }

        return old_to_new[node];

    }
};