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
        map<Node*,Node*>mp;
        Node* tmp=new Node(node->val);
        queue<Node*>q;
        mp[node]=tmp;
        q.push(node);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            for(auto nbr: front->neighbors){
                if(mp.find(nbr)==mp.end()){
                    Node* t1=new Node(nbr->val);
                    mp[nbr]=t1;
                    q.push(nbr);
                }
                mp[front]->neighbors.push_back(mp[nbr]);
            }
        }
        return mp[node];
    }
};