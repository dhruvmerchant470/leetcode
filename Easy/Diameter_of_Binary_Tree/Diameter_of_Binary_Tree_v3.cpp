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
        return 1+max(height(root->left),height(root->right));
    }
    int ans=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        int curr=1+height(root->left)+height(root->right);
        return ans=max(ans,max(curr,max(left,right))-1);
    }
};