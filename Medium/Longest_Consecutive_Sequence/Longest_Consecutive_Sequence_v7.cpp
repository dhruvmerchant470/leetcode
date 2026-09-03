class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       if(n<=1) return n;
       sort(nums.begin(),nums.end());
       int maxi = 1;
       int len=1;
       for(int i=1;i<n;i++){
            if(nums[i-1]+1==nums[i]) len++;
            else if(nums[i-1]!=nums[i]) len=1;
            maxi = max(maxi,len);
       }
       return maxi;
    }
};