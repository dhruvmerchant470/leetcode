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
    TreeNode* head=new TreeNode(0);
    TreeNode* tmp=head;
    void solve(TreeNode* root){
        if(root==NULL) return;
        TreeNode* n1=new TreeNode(root->val);
        tmp->left=NULL; 
        tmp->right=n1;
        tmp=n1;
        solve(root->left);
        solve(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        solve(root);
        *(root)=*(head->right);
    }
};