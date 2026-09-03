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
        vector<pair<int,int>>n1;
        for(int i=0;i<nums.size();i++){
            n1.push_back({nums[i],i});
        }
        sort(n1.begin(),n1.end());
        for(int i=0;i<nums.size();i++){
            int s2=bsearch(n1,target-nums[i],i);
            if(s2!=-1) return {i,s2};
        }
        return {-1,-1};
    }
};