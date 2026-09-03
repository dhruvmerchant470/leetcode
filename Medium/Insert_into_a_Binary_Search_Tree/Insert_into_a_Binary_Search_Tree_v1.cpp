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
        if(root==NULL) {
            TreeNode* n1=new TreeNode(val);
            return n1;
        }
        TreeNode* tmp=root;
        TreeNode* t1=NULL;
        while(tmp!=NULL){
            t1=tmp;
            if(tmp->val>val) tmp=tmp->left;
            else tmp=tmp->right;
        }
        TreeNode* n1=new TreeNode(val);
        if(t1->val>val) t1->left=n1;
        else t1->right=n1;
        return root;
    }
};