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
    int findEle(vector<int>&in, int num){
        for(int i=0;i<in.size();i++) if(in[i]==num) return i;
        return -1;
    }
    TreeNode* help(vector<int>& pre, vector<int>&in, int &pre_index, int in_s,int in_e){
        if(in_s>in_e || pre_index >= pre.size()) return NULL;
        int el = pre[pre_index++];
        TreeNode* root = new TreeNode(el);
        int mid = findEle(in,el);
        root->left = help(pre,in,pre_index,in_s,mid-1);
        root->right = help(pre,in,pre_index,mid+1,in_e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=0;
        TreeNode* ans = help(preorder,inorder,pre,0,preorder.size());
        return ans;
    }
};