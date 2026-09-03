class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++) vec.push_back({nums[i],i});
        sort(vec.begin(),vec.end());
        int i=0,j=vec.size()-1;
        while(i<j){
            int sum = vec[i].first + vec[j].first;
            if(sum==target) return {vec[i].second,vec[j].second};
            else if(sum>target) j--;
            else i++;
        }
        return {};
    }
};