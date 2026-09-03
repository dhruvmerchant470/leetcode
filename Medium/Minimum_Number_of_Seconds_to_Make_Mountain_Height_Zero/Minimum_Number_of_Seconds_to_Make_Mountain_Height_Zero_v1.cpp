class Solution {
public:
    bool isPossible(long long seconds,vector<int>&workerTimes,int mountainHeight){
        long long sum=0;
        for(int i=0;i<workerTimes.size();i++){
            long long w = workerTimes[i];
            // cout<<w + 8.0 * w * seconds<<endl;
            long long val = floor(sqrt(w*w +  8.0 * w * seconds));
            // cout<<val<<endl;
            // cout<<w<<" "<<val<<endl;
            sum += (-w + val) / (2 * w);
        }
        // cout<<seconds<<" "<<sum<<endl;
        return sum>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0,high=LLONG_MAX;
        long long ans = LLONG_MAX;
        while(low<=high){
            long long mid = low + (high-low)/2;
            // cout<<mid<<endl;
            if(isPossible(mid,workerTimes,mountainHeight)){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

};