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
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int left=isBalanced(root->left);
        int right=isBalanced(root->right);
        int l_height=height(root->left);
        int r_height=height(root->right);
        if(left && right && abs(l_height-r_height)<=1) return true;
        else return false;
    }
};