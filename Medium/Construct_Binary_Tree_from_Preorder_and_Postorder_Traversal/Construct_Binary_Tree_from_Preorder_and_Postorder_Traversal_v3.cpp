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
    TreeNode* build(vector<int>&preorder,vector<int>&postorder,int pre_s,int pre_e,int post_s){
        if(pre_s>pre_e) return NULL;

        TreeNode* node = new TreeNode(preorder[pre_s]);
        if(pre_s==pre_e) return node;
        int post_idx = post_s;
        while(postorder[post_idx]!=preorder[pre_s+1]) post_idx+=1;
        int len = post_idx-post_s+1;
        node->left = build(preorder,postorder,pre_s+1,pre_s+len,post_s);
        node->right = build(preorder,postorder,pre_s+len+1,pre_e,post_idx+1);
        return node;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,postorder,0,preorder.size()-1,0);
    }
};