class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if ((mid == 0 && nums[mid] != nums[mid + 1]) ||
                (mid == nums.size() - 1 && nums[mid - 1] != nums[mid]) ||
                nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if(mid&1){
                if(nums[mid]==nums[mid-1]) l = mid+1;
                else h = mid-1;
            }
            else{
                if(nums[mid]==nums[mid-1]) h = mid-1;
                else l = mid+1;
            }
        }
        return nums[l-1];
    }
};