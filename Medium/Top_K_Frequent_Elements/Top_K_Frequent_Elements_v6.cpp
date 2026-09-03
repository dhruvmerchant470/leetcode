class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>count;
        for(auto it: nums) count[it]+=1;
        priority_queue<pair<int,int>>pq;
        for(auto it: count) pq.push({it.second,it.first});
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};