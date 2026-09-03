class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //using sliding window algo
        sort(nums.begin(),nums.end());
        long long int l=0,r=0,total_sum=0,maxi=0;
        while(r<nums.size()){
            total_sum+=nums[r];
            while(l<r && nums[r]*(r-l+1)>total_sum+k){
                total_sum-=nums[l];
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};