class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        vector<int>prefixSum(n+1,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + arr[i];
        }
        for(int i=k;i<=n;i++){
            cnt = cnt + ((prefixSum[i]-prefixSum[i-k])/k>=threshold);
        }
        return cnt;
    }
};