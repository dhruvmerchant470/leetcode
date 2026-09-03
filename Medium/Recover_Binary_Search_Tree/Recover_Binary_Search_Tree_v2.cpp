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
    void inorder(TreeNode* &root,vector<int>&ans,bool en,int &i){
        if(root==NULL) return ;

        inorder(root->left,ans,en,i);
        if(en==1)
        ans.push_back(root->val);
        if(en==0)
        root->val=ans[i++];
        inorder(root->right,ans,en,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        int i=0;
        inorder(root,ans,1,i);
        i=0;
        sort(ans.begin(),ans.end());
        inorder(root,ans,0,i);
    }
};