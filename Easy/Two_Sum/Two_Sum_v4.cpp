class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<pair<int,int>>n1;
        for(int i=0;i<nums.size();i++) n1.push_back({nums[i],i});
        sort(n1.begin(),n1.end());
        while(i<j){
            int sum=n1[i].first+n1[j].first;
            if(sum==target) return {n1[i].second,n1[j].second};
            else if(sum>target) j--;
            else i++;
        }
        return {};
    }
};