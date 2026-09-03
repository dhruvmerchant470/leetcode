class Solution {
public:
    int bsearch(vector<pair<int,int>>&nums, int k, int index){
        int s=0;
        int e=nums.size()-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid].first==k && nums[mid].second!=index) return nums[mid].second;
            else if(nums[mid].first>k) e=mid-1;
            else s=mid+1;
            mid=(s+e)/2;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int t1=target-nums[i];
            if(mp.find(t1)!=mp.end()) return {i,mp[t1]};
            else mp[nums[i]]=i;
        }
        return {};
    }
};