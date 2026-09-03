class Solution {
public:
    class Custom{
        public:
        int start;
        int end;
        int profit;
        Custom(int s,int e,int p){
            start = s;
            end = e;
            profit = p;
        }
    };

    static bool cmp(Custom&a,Custom&b){
        return a.start<b.start;
    }
    int bs(vector<Custom>&arr,int index,int end){
        int s = index;
        int e = arr.size()-1;
        int nxt = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid].start>=end){
                nxt = mid;
                e = mid-1;
            }else{
                s = mid + 1;
            }
        }
        return nxt;
    }
    int solve(vector<Custom>&arr,int index,vector<int>&dp){
        if(index>=arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int nextindex = bs(arr,index+1,arr[index].end);
        int take = arr[index].profit+(nextindex!=-1?solve(arr,nextindex,dp):0);
        int not_take = solve(arr,index+1,dp);
        return dp[index]=max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Custom>arr;
        int n = startTime.size();
        for(int i=0;i<n;i++) arr.emplace_back(startTime[i],endTime[i],profit[i]);
        vector<int>dp(n+1,-1);
        sort(arr.begin(),arr.end(),cmp);
        return solve(arr,0,dp);
    }
};