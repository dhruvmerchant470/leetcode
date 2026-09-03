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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode* curr = root;
        TreeNode* tmp;
        while(curr){
            tmp = curr;
            if(curr->val>val) curr=curr->left;
            else curr = curr->right;
        }
        TreeNode* n = new TreeNode(val);
        if(tmp->val>val) tmp->left = n;
        else tmp->right = n;
        return root;
    }
};