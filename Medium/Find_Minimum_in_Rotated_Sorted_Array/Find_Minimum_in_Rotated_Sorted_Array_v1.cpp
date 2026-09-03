class Solution {
public:
    /*
    APPROACH: BINARY SEARCH
    1. WE CHECK IF THE PREVIOUS AND THE NEXT ELEMENT ARE GREATER THAN THE
    CURRENT ELEMENT THEN CURRENT ELEMENT IS THE ANSWER
    2. ELSE, WE CHECK IF THE PREVIOUS ELEMENT IS
    */
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if(nums.size()==2) return min(nums[0],nums[1]);
        int s = 0;
        vector<int> arr = nums;
        int e = nums.size() - 1;
        while (s <= e) {
            cout<<s<<" "<<e<<endl;
            int mid = (s + e) / 2;
            cout << mid << endl;
            if ((mid == 0 && arr[mid] < arr[mid + 1]) ||
                (mid == e && arr[mid] < arr[mid - 1]) ||
                (mid!=0 && mid!=e && arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])) {
                return arr[mid];
            }
            if (arr[mid] >= arr[0] &&
                arr[mid] >= arr[e]) {
                s = mid + 1;
            } else
                e = mid - 1;
        }
        
        return -1;
    }
};