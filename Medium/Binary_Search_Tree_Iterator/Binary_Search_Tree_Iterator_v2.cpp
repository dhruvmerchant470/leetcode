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
    TreeNode* dummy;
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        dummy=root;
    }
    
    int next() {
        while(dummy){
            s.push(dummy);
            dummy=dummy->left;
        }

        TreeNode* top=s.top();
        s.pop();
        cout<<"hi"<<endl;
        dummy=top->right;
        return top->val;
    }
    
    bool hasNext() {
        return dummy || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */