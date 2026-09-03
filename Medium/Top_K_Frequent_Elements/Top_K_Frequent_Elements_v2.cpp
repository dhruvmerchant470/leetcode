class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]=mp[nums[i]]+1;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp) pq.push({it.second,it.first});
        int cnt=0;
        vector<int>ans;
        while(cnt<k){
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;

    }
};