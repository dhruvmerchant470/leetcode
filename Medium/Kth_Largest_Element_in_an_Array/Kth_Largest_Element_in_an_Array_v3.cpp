class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mp;
        //we require min heap

        for(int i=0;i<k;i++){
            mp.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>mp.top()){
                mp.pop();
                mp.push(nums[i]);
            }
        }
        return mp.top();
    }
};