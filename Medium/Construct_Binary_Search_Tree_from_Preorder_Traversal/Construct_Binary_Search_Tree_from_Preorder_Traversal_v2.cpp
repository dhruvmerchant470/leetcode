/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>nextGreater(vector<int>&vec){
        stack<int>s;
        s.push(-1);
        map<int,int>mp;
        for(int i=vec.size()-1;i>=0;i--){
            while(s.top()!=-1 && vec[s.top()]<vec[i]){
                s.pop();
            } 
            mp[vec[i]]=s.top()==-1?vec.size():s.top();
            s.push(i);
        }
        return mp;
    }
    TreeNode* bst(int &pre_index,int s_index,int e_index,vector<int>&preorder,map<int,int>&mp){
        if(pre_index>=preorder.size() || s_index>e_index) return NULL;
        int node_val=preorder[pre_index++];
        TreeNode* root=new TreeNode(node_val);
        int index=mp[node_val];
        root->left=bst(pre_index,pre_index,index-1,preorder,mp);
        root->right=bst(pre_index,index,e_index,preorder,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        map<int,int>mp=nextGreater(preorder);
        // for(auto it: mp) cout<<it.first<<" "<<it.second<<endl;
        int pre_index=0;
        return bst(pre_index,0,preorder.size(),preorder,mp);
    }
};