#include<bits/stdc++.h>
class Solution {
public:
    
    int solve(vector<vector<char>>& matrix,vector<vector<int>>& dp,int i,int j,int &maxi)
    {
        if(i>=matrix.size()||j>=matrix[0].size())
        {
            return 0;

        }
        if(dp[i][j]!=-1) return dp[i][j]; 

        int right=solve(matrix,dp,i,j+1,maxi);
        int down=solve(matrix,dp,i+1,j,maxi);
        int diagonal=solve(matrix,dp,i+1,j+1,maxi);

        if(matrix[i][j]=='1')
        {
            dp[i][j]=min(right,min(down,diagonal))+1;
            maxi=max(dp[i][j],maxi);
            return dp[i][j];
        }
        else 
        {
            return dp[i][j]=0;
        }

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        int maxi=0;
        solve(matrix,dp,0,0,maxi);
        return pow(maxi,2);
    }
};