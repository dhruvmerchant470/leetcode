class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            int curr_end=intervals[i][1];
            int curr_start=intervals[i][0];
            // cout<<i<<endl;
            while(i+1<intervals.size() && intervals[i+1][0]<=curr_end) {
                curr_end=max(curr_end,intervals[i+1][1]);
                i++;
            }
            ans.push_back({curr_start,curr_end});
        }
        return ans;
    }
};