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
    TreeNode* lca(TreeNode* root,int n1,int n2)
    {
        if(root==NULL){
            return NULL;
        }
        if(root->val==n1||root->val==n2){
            return root;
        }

        TreeNode* left=lca(root->left,n1,n2);
        TreeNode* right=lca(root->right,n1,n2);

        if(left!=NULL&&right!=NULL) return root;
        else if(left!=NULL&&right==NULL) return left;
        else if(left==NULL&&right!=NULL) return right;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return lca(root,p->val,q->val);
    }
};