class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost=0;
        int curr_gas=0;
        int index=0;
        for(int i=0;i<gas.size();i++){
            curr_gas+=gas[i]-cost[i];
            total_gas+=gas[i];
            total_cost+=cost[i];
            if(curr_gas<0){
                curr_gas=0;
                index=i+1;
            }
        }

        return total_gas>=total_cost?index:-1;
    }
};