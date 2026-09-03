/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);

        //level order traversal to establish parent child relation
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                if(front->left) {
                    q.push(front->left);
                    parent[front->left->val]=front;
                }
                if(front->right) {
                    q.push(front->right);
                    parent[front->right->val]=front;
                }
            }
        }
        unordered_map<int,bool>visited;
        q.push(target);
        while(k--&&!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                visited[front->val]=1;
                if(front->left && !visited[front->left->val]){
                    q.push(front->left);
                    visited[front->left->val]=1;
                }
                if(front->right && !visited[front->right->val]){
                    q.push(front->right);
                    visited[front->right->val]=1;
                }
                if(parent[front->val] && !visited[parent[front->val]->val]){
                    q.push(parent[front->val]);
                    visited[parent[front->val]->val]=1;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};