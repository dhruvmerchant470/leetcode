class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times=nums.size()/3;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second>times) ans.push_back(it.first);
        }
        return ans;
    }
};