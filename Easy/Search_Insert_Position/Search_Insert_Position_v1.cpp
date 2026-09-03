class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans_index = -1;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                ans_index = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return (ans_index != -1 && nums[ans_index] == target) ? ans_index
                                                              : ans_index + 1;
    }
};