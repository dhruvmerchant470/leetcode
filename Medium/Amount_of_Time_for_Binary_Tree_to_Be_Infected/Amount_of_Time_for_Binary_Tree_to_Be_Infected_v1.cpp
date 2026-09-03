/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,list<int>>adj;
    void construct_adj(TreeNode* root){
        if(root==NULL) return ;
        if(root->left){
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
        }

        construct_adj(root->left);
        construct_adj(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        construct_adj(root);
        queue<int>q;
        int level=0;
        q.push(start);
        unordered_map<int,bool>visited;
        while(!q.empty()){
            level++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int front=q.front();
                q.pop();
                visited[front]=1;
                for(auto nbr: adj[front]){
                    if(!visited[nbr]){
                        q.push(nbr);
                    }
                }
            }
        }
        return level-1;
    }
};