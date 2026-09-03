class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=1;
        int r=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int curr_min=nums[0];
        while(r<n){
            if(nums[r]-curr_min>k){
                ans++;
                curr_min=nums[r];
            }
            r++;
        }
        
        return ans;
    }
};