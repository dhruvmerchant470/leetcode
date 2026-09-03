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
ListNode* buildNode(vector<int> ans)
{
    
    ListNode* head=new ListNode(ans[0]);
    ListNode* fans=head;
    for(int i=1;i<ans.size();i++) 
    {
        ListNode* tmp=new ListNode(ans[i]);
        head->next=tmp;
        head=tmp;
    }
   
   
    return fans;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
        int n=lists.size();
        if(n==0) return NULL;
        for(int i=0;i<n;i++)
        {
            for(ListNode* tmp=lists[i];tmp!=NULL;tmp=tmp->next)
            {
                ans.push_back(tmp->val);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0) return NULL;
        ListNode* ansNode=buildNode(ans);
        return ansNode;
        
    }
};