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
    void solve(TreeNode* root, int target, vector<int>tmp, vector<vector<int>>&ans){
        if(!root->left && !root->right){
            if(target==0){
                ans.push_back(tmp);
            }
            return;
        }
        if(root->left){
            tmp.push_back(root->left->val);
            solve(root->left,target-root->left->val,tmp,ans);
            tmp.pop_back();
        }
        if(root->right){
            tmp.push_back(root->right->val);
            solve(root->right,target-root->right->val,tmp,ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>>ans;
        solve(root,targetSum-root->val,{root->val},ans);
        return ans;
    }
};