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
    int height(TreeNode* root){
        if(root==NULL) return 0;

        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    void inorder(TreeNode* root,vector<TreeNode*>&ans){
        if(root==NULL) return ;
        inorder(root->left,ans);
        ans.push_back(root);
        inorder(root->right,ans);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        vector<TreeNode*>ans;
        inorder(root,ans);
        for(int i=0;i<ans.size();i++){
            if(abs(height(ans[i]->left)-height(ans[i]->right))>1){
                return false;
            }
        }
        return true;
    }
};