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
    int findelt(int elt,vector<int>inorder){
        
        for(int i=0;i<inorder.size();i++){
            if(elt==inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inS,int inE){
        if(index>=preorder.size()||inS>inE) return NULL;
        int elt=preorder[index++];
        TreeNode* root=new TreeNode(elt);
        int index_elt=findelt(elt,inorder);
        root->left=solve(preorder,inorder,index,inS,index_elt-1);
        root->right=solve(preorder,inorder,index,index_elt+1,inE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return solve(preorder,inorder,index,0,inorder.size());
    }
};