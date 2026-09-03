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
    TreeNode* successor(TreeNode* root){
        TreeNode* tmp=root;
        while(tmp->left!=NULL){
            tmp=tmp->left;
        }
        return tmp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val==key){
            //0 child
            if(root->left==NULL&&root->right==NULL) 
            {
                delete root;
                return NULL;
            }
            //1 child
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode* tmp=root->left;
                delete root;
                return tmp;
            } 

            else if(root->left==NULL&&root->right!=NULL){
                TreeNode* tmp=root->right;
                delete root;
                return tmp;
            } 
            //2 child
            else if(root->left!=NULL&&root->right!=NULL){
                int tmp_val=successor(root->right)->val;
                root->val=tmp_val;
                root->right=deleteNode(root->right,tmp_val);
                return root;
            }

        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};