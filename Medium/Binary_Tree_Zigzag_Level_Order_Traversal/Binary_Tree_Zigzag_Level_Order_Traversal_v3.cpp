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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool flag=true;
        while(!q.empty()){
            int size = q.size();
            vector<int>tmp;
            for(int i=0;i<size;i++){
                auto f = q.front();
                q.pop();
                tmp.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            if(flag) ans.push_back(tmp);
            else{
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
            }
            flag = !flag;
        }
        return ans;
    }
};