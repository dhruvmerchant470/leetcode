class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int product=1;
        int cnt=0;
        int l=0,r=0;
        while(r<nums.size()){
            product*=nums[r];
            while(product>=k){
                product/=nums[l];
                l++;
            } 
            cnt+=(1+r-l);
            r++;
        }
        return cnt;
    }
};