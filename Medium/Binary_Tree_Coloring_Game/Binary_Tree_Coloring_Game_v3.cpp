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
    void inorder(TreeNode* root,int x,TreeNode* &tmp){
        if(root==NULL) return;

        inorder(root->left,x,tmp);
        if(root->val==x) {
            tmp=root;
            return ;
        }
        inorder(root->right,x,tmp);
    }
    void inorder1(TreeNode* root,int &cnt){
        if(root==NULL) return;

        inorder1(root->left,cnt);
        cnt++;
        inorder1(root->right,cnt);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
       TreeNode* tmp;
       inorder(root,x,tmp);

       //option 1 choose y = root->left
       int cnt1=0,cnt2=0,cnt3=0;
        inorder1(tmp->left,cnt1);
        inorder1(tmp->right,cnt2);
        cnt3=n-cnt1-cnt2-1;
        if(cnt1>=(n+1)/2||cnt2>=(n+1)/2||cnt3>=(n+1)/2) return true;
        else return false;
    }
};