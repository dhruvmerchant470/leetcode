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
    TreeNode* solve(vector<int>&nums, int num_s, int num_e){
        if(num_s>=num_e) return NULL;

        int mid=(num_s+num_e)/2;
        // cout<<nums[mid]<<endl;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,num_s,mid);
        root->right=solve(nums,mid+1,num_e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size());
    }
};