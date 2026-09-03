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
    int successor(TreeNode* root){
        TreeNode* tmp = root;
        while(tmp->left!=NULL){
            tmp = tmp->left;
        }
        return tmp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            else if(root->right!=NULL && root->left==NULL){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else{
                int succ = successor(root->right);
                root->val = succ;
                root->right = deleteNode(root->right,succ);
                return root;
            }
        }
        if(key>root->val)  root->right=deleteNode(root->right,key);
        else root->left=deleteNode(root->left,key);
        return root;
    }
};