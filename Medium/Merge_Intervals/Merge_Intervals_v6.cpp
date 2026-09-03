class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>s;
        s.push(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            vector<int>tmp=s.top();
            if(intervals[i][0]<=tmp[1]){
                s.pop();
                s.push({tmp[0],max(intervals[i][1],tmp[1])});
            }
            else s.push(intervals[i]);
        }
        vector<vector<int>>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};