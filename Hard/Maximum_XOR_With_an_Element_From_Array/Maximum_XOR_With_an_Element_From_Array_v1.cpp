struct Node{
    Node* bits[2];
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=num>>i & 1;
            if(!node->bits[bit]) node->bits[bit]=new Node();
            node=node->bits[bit];
        }
    }

    int getMax(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=num>>i & 1;
            if(node->bits[1-bit]){
                maxi=maxi |1<<i;
                node=node->bits[1-bit];
            }
            else node=node->bits[bit];
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>new_q;
        int n=queries.size();
        for(int i=0;i<n;i++) new_q.push_back({queries[i][1],queries[i][0],i});
        sort(new_q.begin(),new_q.end());
        int index=0;
        Trie* t=new Trie();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int xi=new_q[i][1];
            int mi=new_q[i][0];
            int i1=new_q[i][2];
            while(index<nums.size() && nums[index]<=mi){
                t->insert(nums[index]);
                index++;
            }
            if(index==0) ans[i1]=-1;
            else ans[i1]=t->getMax(xi);
        }
        return ans;
    }
};