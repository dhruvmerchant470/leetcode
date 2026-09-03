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
    TreeNode* construct(vector<int>&preorder,int preS,int preE,vector<int>&postorder,int postS){
        if(preS>preE) return NULL;

        int elt=preorder[preS];
        TreeNode* root=new TreeNode(elt);
        if(preS==preE) return root;
        int postIndex=postS;
        while(postorder[postIndex]!=preorder[preS+1]) postIndex++;
        int len=postIndex-postS+1;
        root->left=construct(preorder,preS+1,preS+len,postorder,postS);
        root->right=construct(preorder,preS+len+1,preE,postorder,postIndex+1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(preorder,0,preorder.size()-1,postorder,0);
    }
};