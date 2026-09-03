class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<int,unordered_map<int,int>>dp;
        int mini=INT_MAX;
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
                else if(j==triangle[i].size()-1) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                else dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        for(auto it: dp[triangle.size()-1]){
            mini=min(mini,it.second);
        }
        return mini;
    }
};