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
unordered_map<int,int>mp;
    TreeNode* solve(vector<int>&postorder,vector<int>&inorder,int &post_index,int in_start,int in_end){
        if(in_start>=in_end || post_index<0) return NULL;

        int tmp=postorder[post_index--];
        TreeNode* root=new TreeNode(tmp);
        int index=mp[tmp];
        root->right=solve(postorder,inorder,post_index,index+1,in_end);
        root->left=solve(postorder,inorder,post_index,in_start,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int post_index=n-1;
        return solve(postorder,inorder,post_index,0,n);
    }
};