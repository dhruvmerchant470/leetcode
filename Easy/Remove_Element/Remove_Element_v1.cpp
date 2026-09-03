class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s=0,e=nums.size()-1;
        int cnt=0;
        for(auto it: nums) if(it!=val) cnt++;
        while(s<e){
            while(s<e && nums[s]!=val) s++;
            while(s<e && nums[e]==val) e--;
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
        return cnt;
    }
};