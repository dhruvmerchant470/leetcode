class Solution {
public:
    int solve(vector<int>& arr, int  l,int r,map<pair<int,int>,int>&maxi,vector<vector<int>>&dp)
{
    if(l==r) return 0; //a single leaf node can't make a parent node
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=INT_MAX;
    // do partions
    for(int k=l;k<r;k++)
    {
        ans=min(ans,(maxi[{l,k}]*maxi[{k+1,r}])+solve(arr,l,k,maxi,dp)+solve(arr,k+1,r,maxi,dp));
    }
    return dp[l][r]=ans;

}
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<n;j++)
            {
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        
        return solve(arr,0,n-1,maxi,dp);
    }
};