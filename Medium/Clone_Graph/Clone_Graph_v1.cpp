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
    unordered_map<Node*,Node*>copies;
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        queue<Node*>q;
        Node* tmp=new Node(node->val,{});
        copies[node]=tmp;
        q.push(node);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto nbr:front->neighbors){
                if(copies.find(nbr)==copies.end()){
                    Node* tmp1=new Node(nbr->val,{});
                    copies[nbr]=tmp1;
                    q.push(nbr);
                }
                copies[front]->neighbors.push_back(copies[nbr]);
            }
        }
        return tmp;
    }
};