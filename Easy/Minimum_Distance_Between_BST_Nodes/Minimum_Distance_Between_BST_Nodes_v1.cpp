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
    void inorder(vector<int> &ans,TreeNode* root){
        if(!root) return;

        inorder(ans,root->left);
        // if(root->left) ans=min(ans,abs(root->val-root->left->val));
        // if(root->right) ans=min(ans,abs(root->val-root->right->val));
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inorder(ans,root);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        int ans1=INT_MAX;
        for(int i=1;i<ans.size();i++){
            ans1=min(ans1,abs(ans[i]-ans[i-1]));
        }
        return ans1;
    }
};