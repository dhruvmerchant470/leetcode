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
    map<TreeNode*,TreeNode*>mp;
    TreeNode* sta=nullptr;
    void traverse(TreeNode* root,int start){
        if(!root) return;
        if(root->val==start) sta=root;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        traverse(root->left,start);
        traverse(root->right,start);

    }
    int amountOfTime(TreeNode* root, int start) {
        traverse(root,start);
        queue<TreeNode*>q;
        map<TreeNode*,bool>visited;
        q.push(sta);
        visited[sta]=1;
        int t=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                if(top->left && !visited[top->left]) {
                    q.push(top->left);
                    visited[top->left]=1;
                }
                if(top->right && !visited[top->right]) {
                    q.push(top->right);
                    visited[top->right]=1;
                }
                if(mp[top] && !visited[mp[top]]){
                    q.push(mp[top]);
                    visited[mp[top]]=1;
                }
            }
            t++;
        }
        return t-1;
    }
};