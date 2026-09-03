class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int bs(vector<vector<int>>&events,int start){
        int low=0;
        int high=events.size()-1;
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][1]<start){
                result=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return result;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),cmp);
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++){
            int index=bs(events,events[i-1][0]);
            for(int j=1;j<=k;j++){
                dp[i][j]=max(dp[i-1][j],dp[index+1][j-1]+events[i-1][2]);
            }
        }
        return dp[n][k];
    }
    
};