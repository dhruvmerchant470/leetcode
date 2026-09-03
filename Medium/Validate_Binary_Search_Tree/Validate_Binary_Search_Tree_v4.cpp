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
    bool solve(TreeNode* root,ll mini,ll maxi){
        if(!root) return true;
        if(root->val>=maxi || root->val<=mini) return false;
        return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return solve(root->left,LLONG_MIN,root->val) && solve(root->right,root->val,LLONG_MAX);
    }
};