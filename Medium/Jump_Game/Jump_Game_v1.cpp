class Solution {
public:
    bool pos(int i,int index,vector<int>&dp){
        for(int k=i;k<=index;k++){
            if(dp[k]) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[n-1]=1;
        for(int i=n-1;i>=0;i--){
            int index=i+nums[i];
            if(index>=n-1 || pos(i,index,dp)) dp[i]=1;
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[0];
    }
};