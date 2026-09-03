class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int curr = INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            int t = landStartTime[i] + landDuration[i];
            for(int j=0;j<waterStartTime.size();j++){
                int t2 = t;
                if(waterStartTime[j]>=t){
                    t2 += (waterStartTime[j]-t)+waterDuration[j];
                }else{
                    t2 += waterDuration[j];
                }
                curr = min(curr,t2);
            }
        }

        for(int i=0;i<waterStartTime.size();i++){
            int t = waterStartTime[i] + waterDuration[i];
            for(int j=0;j<landStartTime.size();j++){
                int t2 = t;
                if(landStartTime[j]>=t){
                    t2 += (landStartTime[j]-t)+landDuration[j];
                }else{
                    t2 += landDuration[j];
                }
                curr = min(curr,t2);
            }
        }
        return curr;
    }
};