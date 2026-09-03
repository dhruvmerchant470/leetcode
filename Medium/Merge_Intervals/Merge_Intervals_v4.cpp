class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>s;
        s.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto top=s.top();
            if(top[1]>=intervals[i][0]){
                vector<int>tmp={min(top[0],intervals[i][0]),max(top[1],intervals[i][1])};
                s.pop();
                s.push(tmp);
            }
            else s.push(intervals[i]);
        }
        vector<vector<int>>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;

    }
};