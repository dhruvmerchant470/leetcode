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
    int find_i(vector<int>&inorder,int num){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==num){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &pre_start,int in_s,int in_e){
        if(in_s>in_e || pre_start>=preorder.size()) return NULL;
        TreeNode* node = new TreeNode(preorder[pre_start]);
        int find_idx = find_i(inorder,preorder[pre_start]);
        pre_start+=1;
        node->left = build(preorder,inorder,pre_start,in_s,find_idx-1);
        node->right = build(preorder,inorder,pre_start,find_idx+1,in_e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int pre_i = 0;
        return build(preorder,inorder,pre_i,0,n-1);
    }
};