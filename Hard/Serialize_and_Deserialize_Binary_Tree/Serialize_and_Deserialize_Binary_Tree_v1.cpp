/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(top->val) + ',');
            }
            if (top) {
                q.push(top->left);
                q.push(top->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        stringstream ss(data);
        string tmp;
        getline(ss, tmp, ',');
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            getline(ss, tmp, ',');
            if (tmp == "#") {
                top->left = NULL;
            } else {
                top->left = new TreeNode(stoi(tmp));
                q.push(top->left);
            }
            getline(ss, tmp, ',');
            if (tmp == "#")
                top->right = NULL;
            else {
                top->right = new TreeNode(stoi(tmp));
                q.push(top->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));