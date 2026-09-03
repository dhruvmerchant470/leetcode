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
class BSTIterator {
public:
    vector<int>in;
    int index;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        index=0;
        inorder(root);
    }
    
    
    int next() {
        return in[index++];
    }
    
    bool hasNext() {
        if(index>=in.size()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */