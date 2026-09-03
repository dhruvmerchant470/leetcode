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
    int sum=0;
    void solve(TreeNode* root,string tmp){
        if(root==NULL) return;
        if(!root->left && !root->right){
            tmp.push_back(root->val+'0');
            sum+=stoi(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val+'0');
        solve(root->left,tmp);
        solve(root->right,tmp);
        tmp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        solve(root,"");
        return sum;
    }
};