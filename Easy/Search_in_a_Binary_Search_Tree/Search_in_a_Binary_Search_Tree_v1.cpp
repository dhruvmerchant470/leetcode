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
    void search(TreeNode* root, TreeNode* &ans,int val){
        if(root==NULL) return ;
        if(root->val==val) {
            ans=root;
            return;
        }
        else if(root->val>val) search(root->left,ans,val);
        else search(root->right,ans,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=NULL;
        search(root,ans,val);
        return ans;
    }
};