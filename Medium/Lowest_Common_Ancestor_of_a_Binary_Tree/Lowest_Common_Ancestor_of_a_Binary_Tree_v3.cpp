/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* help(TreeNode* root,int p, int q){
        if(!root) return NULL;
        if(root->val==p || root->val==q) return root;
        TreeNode* left = help(root->left,p,q);
        TreeNode* right = help(root->right,p,q);
        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return help(root,p->val,q->val);
    }
};