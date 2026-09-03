class Solution {
public:
    int solve(vector<int>& first, vector<int>& firstD, vector<int>& second, vector<int>& secondD) {
        int first_fin = INT_MAX;
        for(int i=0;i<first.size();i++) first_fin = min(first_fin,first[i]+firstD[i]);
        int ans = INT_MAX;
        for(int i=0;i<second.size();i++){
            int start = max(first_fin,second[i]);
            int end = start + secondD[i];
            ans = min(ans,end);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int water = solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(land,water);
    }
};