class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp,bool swapped,int index)
    {
        if(index==nums1.size()) return 0;
        if(dp[index][swapped]!=-1) return dp[index][swapped];
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        int ans=INT_MAX;
        if(swapped)
        {
            swap(prev1,prev2);
        }
        //no swap
        if(nums1[index]>prev1&&nums2[index]>prev2)
        {
            ans=solve(nums1,nums2,dp,0,index+1);
        }
        if(nums1[index]>prev2&&nums2[index]>prev1)
        ans=min(ans,1+solve(nums1,nums2,dp,1,index+1));

        return dp[index][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(nums1,nums2,dp,0,1);
    }
};