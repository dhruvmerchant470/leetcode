/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        vector<vector<Node*>>vec;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*>tmp;
            for(int i=0;i<size;i++){
                auto node=q.front();
                tmp.push_back(node);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            vec.push_back(tmp);
        }

        
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size()-1;j++){
                vec[i][j]->next=vec[i][j+1];
            }
            vec[i][vec[i].size()-1]->next=NULL;
        }
        return root;
    }
};