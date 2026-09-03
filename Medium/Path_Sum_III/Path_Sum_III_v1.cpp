/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    #define ll long long
    ll cnt = 0;
    void inorder(TreeNode* root,vector<TreeNode*>&nodes){
        if(!root) return;
        nodes.push_back(root);
        inorder(root->left,nodes);
        inorder(root->right,nodes);
    }
    void solve(TreeNode* root, ll target){
        if(!root) return;
        if(target==0) cnt+=1;
        if(root->left) solve(root->left,target-root->left->val);
        if(root->right) solve(root->right,target-root->right->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        vector<TreeNode*>nodes;
        inorder(root,nodes);
        for(auto it: nodes){
            solve(it,targetSum-it->val);
        }
        return cnt;
    }
};