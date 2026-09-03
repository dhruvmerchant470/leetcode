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

class nodes{
    public:
        int val;
        int row;
        int col;
    nodes(int v,int r, int c){
        val=v;
        row=r;
        col=c;
    }
};

void traversal(TreeNode* root,int row,int col,vector<nodes>&v){
    if(root==NULL) return;
    v.emplace_back(root->val,row,col);
    traversal(root->left,row+1,col-1,v);
    traversal(root->right,row+1,col+1,v);
}
static bool cmp(nodes &a,nodes &b){
    if(a.col!=b.col) return a.col<b.col;
    if(a.row!=b.row) return a.row<b.row;
    return a.val<b.val;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<nodes>v;
        traversal(root,0,0,v);
        sort(v.begin(),v.end(),cmp);
        vector<vector<int>>ans;
        int last_col=INT_MIN;
        // for(auto tmp:v) cout<<tmp.val<<" "<<tmp.row<<" "<<tmp.col<<endl;
        for(auto tmp:v){
            if(tmp.col!=last_col){
                ans.push_back({});
                last_col=tmp.col;
            }
            ans.back().push_back(tmp.val);
        }
        return ans;
    }
};