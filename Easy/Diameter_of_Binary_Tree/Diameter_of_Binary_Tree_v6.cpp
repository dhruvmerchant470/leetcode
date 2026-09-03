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
        auto left=dia(root->left);
        auto right=dia(root->right);
        return {1+max(left.first,right.first),max(max(left.second,right.second),1+left.first+right.first)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).second-1;
    }
};