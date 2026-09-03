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
    int findelt(vector<int>&inorder,int elt){
        for(int i=0;i<inorder.size();i++) if(inorder[i]==elt) return i;
        return -1;
    }
    TreeNode* construct(vector<int>&inorder,vector<int>&postorder,int inS,int inE,int &index){
        if(index<0||inS>inE) return NULL;

        int elt=postorder[index--];
        TreeNode* root=new TreeNode(elt);
        int pos=findelt(inorder,elt);
        root->right=construct(inorder,postorder,pos+1,inE,index);
        root->left=construct(inorder,postorder,inS,pos-1,index);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        return construct(inorder,postorder,0,inorder.size()-1,index);
    }
};