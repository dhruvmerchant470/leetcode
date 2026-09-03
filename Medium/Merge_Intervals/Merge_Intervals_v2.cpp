class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>s;
        s.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto top=s.top();
            if(top[1]>=intervals[i][0]){
                s.pop();
                s.push({top[0],max(top[1],intervals[i][1])});
            }
            else s.push(intervals[i]);
        }    
        vector<vector<int>>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};