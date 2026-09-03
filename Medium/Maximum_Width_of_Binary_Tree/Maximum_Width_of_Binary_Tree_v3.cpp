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
        //level order traversal
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        int ans = INT_MIN;
        q.push({root,0});
        int first,last;
        while(!q.empty()){
            int size = q.size();
            int f = q.front().second;
            for(int i=0;i<size;i++){
                auto front = q.front();
                q.pop();
                if(i==0) first = front.second;
                if(i==size-1) last = front.second;
                int curr_index = front.second - f;
                if(front.first->left) q.push({front.first->left,1LL*2*curr_index+1});
                if(front.first->right) q.push({front.first->right,1LL*2*curr_index+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};