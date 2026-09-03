class Solution {
public:
    int first(vector<int>&nums,int target,bool flag){
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                if(flag) low=mid+1;
                else high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target,0),first(nums,target,1)};
    }
};