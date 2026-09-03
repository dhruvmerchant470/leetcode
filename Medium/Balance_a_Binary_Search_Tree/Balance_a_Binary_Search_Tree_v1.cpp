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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* balance(vector<int>ans,int l,int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* y=new TreeNode(ans[mid]);
        y->left=balance(ans,l,mid-1);
        y->right=balance(ans,mid+1,r);

        return y;
    }
    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>ans;
        inorder(root,ans);
        TreeNode* a1=balance(ans,0,ans.size()-1);
        return a1;
    }
};