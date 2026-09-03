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
        bool flag=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int size=q.size();
            vector<int>tmp;
            for(int i=0;i<size;i++){
                auto t1=q.front();
                q.pop();
                tmp.push_back(t1->val);
                if(t1->left) q.push(t1->left);
                if(t1->right) q.push(t1->right);
            }
            if(flag) {
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
            }
            else ans.push_back(tmp);
            flag=!flag;
        }
        return ans;
    }
};