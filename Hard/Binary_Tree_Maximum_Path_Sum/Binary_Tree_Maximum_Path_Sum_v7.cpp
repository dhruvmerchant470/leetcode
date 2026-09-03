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
    int max_sum(TreeNode* root,int &res){
        if(!root) return 0;
        int left = max(0,max_sum(root->left,res));
        int right = max(0,max_sum(root->right,res));
        int curr = root->val + max(left,right);
        res = max(res,root->val+left+right);
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        max_sum(root,ans);
        return ans;
    }
};