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
    struct node{
        int sum;
        bool isBst;
        int maxi;
        int mini;
    };
    int ans = INT_MIN;
    node* solve(TreeNode* root){
        if(!root){
            node* n = new node();
            n->sum = 0;
            n->maxi = INT_MIN;
            n->mini = INT_MAX;
            n->isBst = true;
            return n;
        }

        node* left = solve(root->left);
        node* right = solve(root->right);
        node *n = new node();
        n->maxi = max(root->val,right->maxi);
        n->mini = min(root->val,left->mini);
        if(left->isBst && right->isBst && left->maxi < root->val && right->mini > root->val){
            n->sum = left->sum + right->sum + root->val;
            n->isBst = true;
        }else{
            n->sum = 0;
            n->isBst = false;
        }
        ans = max(ans,n->sum);
        return n;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;  
    }
};