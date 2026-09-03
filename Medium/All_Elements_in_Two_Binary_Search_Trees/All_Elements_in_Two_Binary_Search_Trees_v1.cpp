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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>s1,s2;
        TreeNode* curr1 = root1;
        TreeNode* curr2 = root2;
        vector<int>ans;
        while(true){
            while(curr1){
                s1.push(curr1);
                curr1 = curr1->left;
            }
            while(curr2){
                s2.push(curr2);
                curr2 = curr2->left;
            }
            if(s1.empty() && s2.empty()) break;

            TreeNode* t1 =NULL;
            if(!s1.empty()) t1 = s1.top();
            TreeNode* t2 = NULL;
            if(!s2.empty()) t2 = s2.top();
            if(t1 && t2){
                if(t1->val>t2->val){
                    ans.push_back(t2->val);
                    curr2 = t2->right;
                    s2.pop();
                }else{
                    ans.push_back(t1->val);
                    curr1 = t1->right;
                    s1.pop();
                }    
            }else if(t1){
                ans.push_back(t1->val);
                curr1 = t1->right;
                s1.pop();
            }
            else{
                ans.push_back(t2->val);
                curr2 = t2->right;
                s2.pop();
            }
        }
        return ans;
    }
};