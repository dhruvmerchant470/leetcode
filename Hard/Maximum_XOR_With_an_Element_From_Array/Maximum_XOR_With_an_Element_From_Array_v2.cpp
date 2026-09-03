class Node{
    public:
    Node* child[2];
};

class Trie{
    public:
    Node* root;
    Trie() { root = new Node(); }
    void insert(int num){
        Node* tmp = root;
        for(int i=31;i>=0;i--){
            int digi = num>>i & 1;
            if(tmp->child[digi]==NULL){
                tmp->child[digi]=new Node();
            }
            tmp = tmp->child[digi];
        }
    }

    int getMax(int num){
        Node* tmp = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int digi = num>>i & 1;
            if(tmp->child[1-digi]){
                tmp = tmp->child[1-digi];
                ans |= 1<<i;
            }
            else{
                tmp = tmp->child[digi];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());
        int index = 0;
        vector<int>ans(q.size());
        Trie* t = new Trie();
        for(int i=0;i<q.size();i++){
            while(index<nums.size() && nums[index]<=q[i][0]){
                t->insert(nums[index]);
                index++;
            }
            if(index==0) ans[q[i][2]]=-1;
            else{
                ans[q[i][2]]=t->getMax(q[i][1]);
            }
        }
        return ans;
    }
};