class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>>s;
        s.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            pair<int,int> top=s.top();
            if(top.second<intervals[i][0]) s.push({intervals[i][0],intervals[i][1]});
            else{
                s.pop();
                int end=max(top.second,intervals[i][1]);
                s.push({top.first,end});
            }
        }
        vector<vector<int>>ans;
        while(!s.empty()){
            vector<int>tmp;
            tmp.push_back(s.top().first);
            tmp.push_back(s.top().second);
            ans.push_back(tmp);
            s.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};