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
    int find(vector<int>&inorder,int data){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==data) return i;
        }
        return -1;
    }
    TreeNode* help(vector<int>&inorder,vector<int>&postorder,int &post_index,int inS,int inE){
        if(post_index<0 || inS>inE) return NULL;
        int data = postorder[post_index--];
        TreeNode* root = new TreeNode(data);
        int idx = find(inorder,data);
        root->right = help(inorder,postorder,post_index,idx+1,inE);
        root->left = help(inorder,postorder,post_index,inS,idx-1); 
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        return help(inorder,postorder,idx,0,inorder.size()-1);
    }
};