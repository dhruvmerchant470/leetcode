class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = INT_MAX,maxi =INT_MIN;
        for(auto it: nums){
            mini = min(mini,it*1LL);
            maxi = max(maxi,it*1LL);
        }

        return k*(maxi-mini)*1LL;
    }
};