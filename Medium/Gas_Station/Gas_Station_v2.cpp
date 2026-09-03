class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=gas.size();
        int index=-1;
        for(int i=0;i<n;i++){
            int sum=gas[i];
            if(sum<cost[i]) continue;
            for(int j=0;j<n-1;j++){
               if(sum-cost[(i+j)%n]<=0) {
                sum=-1;
                break;
               }
               sum= sum-cost[(i+j)%n]+gas[(i+j+1)%n];   
            }
            // cout<<sum<<" "<<i<<endl;
            if(sum!=-1 && sum>=cost[(n+i-1)%n]){
                index=i;
                break;
            }
        }
        return index;
    }
};