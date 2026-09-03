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
    pair<int,int>dia(TreeNode* root){
        if(root==NULL) return {0,0};

        pair<int,int>left=dia(root->left);
        pair<int,int>right=dia(root->right);
        int height=max(left.second,right.second)+1;
        int diameter=max(left.first,max(right.first,left.second+right.second+1));
        return {diameter,height};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).first-1;
    }
};