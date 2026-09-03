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
        int maxi=0;
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));

        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                int right=dp[i][j-1];
                int down=dp[i-1][j];
                int dia=dp[i-1][j-1];
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=1+min(right,min(down,dia));
                    maxi=max(maxi,dp[i][j]);
                }
               
            }
        }
        return maxi*maxi;
    }
};