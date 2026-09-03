class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int s = 0;
        vector<int> arr = nums;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if ((mid == 0 && arr[mid] > arr[mid + 1]) ||
                (mid == e && arr[mid] > arr[mid - 1]) ||
                (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])) {
                return mid;
            } else if ((mid == e || arr[mid] < arr[mid + 1]) &&
                       (mid == 0 || arr[mid] > arr[mid - 1]))
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};