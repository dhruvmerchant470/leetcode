class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=1;
        int max_end=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(max_end<=intervals[i][0]){
                cnt++;
                max_end=max(intervals[i][1],max_end);
            }
        }
        return n-cnt;
    }
};