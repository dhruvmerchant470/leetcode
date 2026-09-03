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
private:
    vector<TreeNode*>Nodes;
public:
    void recurse(TreeNode* root ,int target){
        if(root==NULL) return;
        if(root->val==target) Nodes.push_back(root);
        recurse(root->left,target);
        recurse(root->right,target);
    }
    bool cmp(TreeNode* root,TreeNode* sub){
        if(root==NULL && sub==NULL) return true;
        else if(root && !sub) return false;
        else if(!root && sub) return false;
        if(root->val != sub->val) return false;
        bool left=cmp(root->left,sub->left);
        bool right=cmp(root->right,sub->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        recurse(root,subRoot->val);
        for(int i=0;i<Nodes.size();i++){
            if(cmp(Nodes[i],subRoot)) return true;
        }
        return false;
    }
};