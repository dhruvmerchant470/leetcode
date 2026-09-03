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
        vector<int>next(col+1,0);
        vector<int>curr(col+1,0);

        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                int right=curr[j+1];
                int down=next[j];
                int dia=next[j+1];
                if(matrix[i][j]=='1')
                {
                    curr[j]=1+min(right,min(down,dia));
                    maxi=max(maxi,curr[j]);
                }
                else
                {
                    curr[j]=0;
                }
               
            }
            next=curr;
        }
        return maxi*maxi;
    }
};