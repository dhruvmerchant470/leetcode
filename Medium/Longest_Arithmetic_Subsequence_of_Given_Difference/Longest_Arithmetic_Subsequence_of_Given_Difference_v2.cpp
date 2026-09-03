class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int tmp=arr[i]-difference;
            int tmpAns=0;
            if(dp[tmp])
            {
                tmpAns=dp[tmp];

            }
            dp[arr[i]]=1+tmpAns;
            ans=max(ans,dp[arr[i]]);
        }
    return ans;
    }
};