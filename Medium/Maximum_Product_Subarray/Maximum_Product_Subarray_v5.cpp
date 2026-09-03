class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_p = 1;
        int curr_s = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            curr_p*=nums[i];
            curr_s*=nums[n-i-1];
            maxi = max({maxi,curr_p,curr_s});
            if(curr_p==0) curr_p=1;
            if(curr_s==0) curr_s=1;
        }
        return maxi;
    }
};