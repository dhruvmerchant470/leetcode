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
    class Node{
        public:
        int row;
        int col;
        int val;
        Node(int r,int c, int v){
            row = r;
            col = c;
            val = v;
        }
        void print(){
            cout<<val<<" "<<row<<" "<<col<<endl;
        }
    };
public:
    static bool cmp(Node* a,Node* b){
        if(a->col!=b->col) return a->col<b->col;
        if(a->row!=b->row) return a->row<b->row;
        return a->val<b->val;
    }
    void inorder(vector<Node*>&v,TreeNode* root,int r,int c){
        if(!root) return;
        inorder(v,root->left,r+1,c-1);
        Node* n = new Node(r,c,root->val);
        v.push_back(n);
        inorder(v,root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Node*>v;
        inorder(v,root,0,0);
        sort(v.begin(),v.end(),cmp);
        // for(auto it: v){
        //     it->print();
        // }
        vector<vector<int>>ans;
        int prev=INT_MIN;
        for(auto it: v){
            if(it->col!=prev){
                prev = it->col;
                ans.push_back({});
            }
            ans.back().push_back(it->val);
        }
        return ans;
    }
};