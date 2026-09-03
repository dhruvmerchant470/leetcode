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
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int &pre_index,int in_start,int in_end){
        if(in_start>=in_end || pre_index>=preorder.size()) return NULL;

        int tmp=preorder[pre_index++];
        TreeNode* root=new TreeNode(tmp);
        int index=mp[tmp];
        // cout<<index<<endl;
        root->left=solve(preorder,inorder,pre_index,in_start,index);
        root->right=solve(preorder,inorder,pre_index,index+1,in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int pre_index=0;
        return solve(preorder,inorder,pre_index,0,n);
    }
};