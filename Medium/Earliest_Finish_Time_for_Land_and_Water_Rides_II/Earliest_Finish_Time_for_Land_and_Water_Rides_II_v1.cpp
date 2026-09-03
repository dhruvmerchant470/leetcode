class Solution {
public:
    int solve(vector<int>& landS, vector<int>& landD, vector<int>& waterS, vector<int>& waterD) {
        int first = INT_MAX;
        for(int i=0;i<landS.size();i++){
            first = min(first,landS[i]+landD[i]);
        }

        int ans = INT_MAX;
        for(int i=0;i<waterS.size();i++){
            if(waterS[i]<=first){
                ans = min(ans,first+waterD[i]);
            }else{
                ans = min(ans,first+(waterS[i]-first)+waterD[i]);
            }
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int water = solve(waterStartTime,waterDuration,landStartTime,landDuration);
        // cout<<land<<" "<<water<<endl;
        return min(land,water);
    }
};