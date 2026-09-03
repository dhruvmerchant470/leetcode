class Solution {
public:
    bool check(int diff, int pairs, vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if(nums[i]-nums[i-1]<=diff){
                cnt++;
                i++;
            }
        }
        return cnt >= pairs;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        int maxi = INT_MIN;
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n-1]-nums[0];
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, p, nums)) {
                result = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return result;
    }
};