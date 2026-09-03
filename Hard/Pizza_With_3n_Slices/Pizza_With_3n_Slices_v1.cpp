class Solution {
public:
int LIS(vector<int>&slices ,int index,int endIndex,int n,vector<vector<int>>&dp)
{
    if(index>endIndex||n==0) return 0;
    if(dp[index][n]!=-1)  return dp[index][n];
    int include=slices[index]+LIS(slices,index+2,endIndex,n-1,dp);
    int exclude=LIS(slices,index+1,endIndex,n,dp);
    return dp[index][n]=max(include,exclude);
}
    int maxSizeSlices(vector<int>& slices) {
      
      int n=slices.size();
      vector<vector<int>>dp1(n,vector<int>(n,-1));
      int case1=LIS(slices,0,n-2,n/3,dp1);
      vector<vector<int>>dp2(n,vector<int>(n,-1));
      int case2=LIS(slices,1,n-1,n/3,dp2);
      cout<<case1<<" "<<case2;
      return max(case1,case2);
    }
};