class Custom{
    public: 
    int start;
    int end;
    int profit;
    Custom(int s,int e,int p){
        start=s;
        end=e;
        profit=p;
    }
};
class Solution {
public:
    int getNext(vector<Custom>&arr,int start,int endindex){
        int  s=start;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid].start>=endindex){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
    int solve(vector<Custom>&arr,int index,vector<int>&dp){
        if(index>=arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int nextindex=getNext(arr,index+1,arr[index].end);
        int take=arr[index].profit+solve(arr,nextindex,dp);
        int nottake=solve(arr,index+1,dp);
        return dp[index]=max(take,nottake);
    }
    static bool cmp(Custom &a,Custom &b){
        return a.start<b.start;
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n=start.size();
        vector<Custom>arr;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++) arr.emplace_back(start[i],end[i],profit[i]);
        sort(arr.begin(),arr.end(),cmp);
        return solve(arr,0,dp);
    }
};