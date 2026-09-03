class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];
    }
    void print(vector<vector<int>>&vec){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
        }
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 1;
        sort(intervals.begin(),intervals.end(),cmp);
        // print(intervals);
        int cnt=1;
        int maxi_end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]<=maxi_end) continue;
            maxi_end = intervals[i][1];
            cnt+=1;
        }
        return cnt;
    }
};