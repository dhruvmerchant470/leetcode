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
struct node{
    int data;
    int sum;
    bool isBst;
    int maxi;
    int mini;
};

class Solution {
public:
    node* help(TreeNode* root, int &ans){
        if(root==NULL){
            node* tmp=new node();
            tmp->data=0;
            tmp->sum=0;
            tmp->isBst=true;
            tmp->maxi=INT_MIN;
            tmp->mini=INT_MAX;
            return tmp;
        }
        node* left=help(root->left,ans);
        node* right=help(root->right,ans);
        node* curr=new node();
        curr->maxi=max(root->val,right->maxi);
        curr->mini=min(root->val,left->mini);
        curr->data=root->val;
        if(left->isBst && right->isBst && curr->data>left->maxi && curr->data<right->mini){
            curr->isBst=1;
            curr->sum=left->sum+right->sum+curr->data;
        }
        else{
            curr->isBst=0;
            curr->sum=0;
        }
        ans=max(ans,curr->sum);        
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;
        help(root,ans);
        return ans;
    }
};