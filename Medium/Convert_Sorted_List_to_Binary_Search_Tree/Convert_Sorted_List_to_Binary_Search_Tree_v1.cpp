/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* balance(vector<int>&arr,int l,int r){
        if(l>r) return NULL;

        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=balance(arr,l,mid-1);
        root->right=balance(arr,mid+1,r);

        return root;
    }
    vector<int>convert(ListNode* head){
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        return ans;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>tmp=convert(head);
        return balance(tmp,0,tmp.size()-1);
    }
};