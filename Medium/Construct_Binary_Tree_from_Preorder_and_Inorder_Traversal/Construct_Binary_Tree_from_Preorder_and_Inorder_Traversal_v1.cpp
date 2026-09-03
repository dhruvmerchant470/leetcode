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
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==elt) return i;
        }
        return -1;
    }
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int inS,int inE,int &index){
        if(index>=preorder.size()||inS>inE) return NULL;

        int elt=preorder[index++];
        TreeNode* root=new TreeNode(elt);
        int pos=findelt(inorder,elt);
        root->left=construct(preorder,inorder,inS,pos-1,index);
        root->right=construct(preorder,inorder,pos+1,inE,index);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return construct(preorder,inorder,0,inorder.size()-1,index);
    }
};