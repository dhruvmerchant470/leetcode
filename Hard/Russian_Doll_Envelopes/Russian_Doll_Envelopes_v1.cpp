class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
  
    int solve(vector<int>&a,int n,int curr,int prev,vector<vector<int>>&dp)
    {
        if(curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int include=0;
        if(prev==-1||a[curr]>a[prev])
        include=1+solve(a,n,curr+1,curr,dp);
        
        int exclude=solve(a,n,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
        
        // return dp[curr][prev+1];
    }
    int solveSo(vector<int>&heights)

    {
        int n=heights.size();
        vector<int>nxt(n+1,0);
        vector<int>curra(n+1,0);
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev >= -1;prev--)
            {
                int include=0;
                if(prev==-1||heights[curr]>heights[prev])
                include=1+nxt[curr];

                int exclude=nxt[prev+1];
                curra[prev+1]=max(include,exclude);
            }
            nxt=curra;
        }
        return curra[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>ans;
        int n=envelopes.size();
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1]>ans.back()) ans.push_back(envelopes[i][1]);
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        
        return ans.size();
        
    }
};