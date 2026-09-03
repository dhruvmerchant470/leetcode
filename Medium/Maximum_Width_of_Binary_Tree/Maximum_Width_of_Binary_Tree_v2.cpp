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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            // int mini=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int curr_index=q.front().second;
                auto top=q.front();
                q.pop();
                if(i==0) first=curr_index;
                if(i==size-1) last=curr_index;
                if(top.first->left) q.push({top.first->left,1LL*curr_index*2+1});
                if(top.first->right) q.push({top.first->right,1LL*curr_index*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};