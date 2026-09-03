class Solution {
public:
/*
CASES

CASE1: ALL POSITIVE: PRODUCT OF ALL ELEMENTS
CASE2: EVEN NEGATIVES: PRODUCT OF ALL ELEMENTS
CASE3: ODD NEGATIVES
CASE4: ZEROS

APPROACH:
PREFIX PRODUCT
SUFFIX PRODUCT

E.G. [2,3,-2,4]
PREFIX [2,6,-12,-48]
SUFFIX [-48, -24, -8,4] 
MAX AT EACH INDEX SO ANS IS 6

AT ANY INDEX IF PREFIX OR SUFFIX IS 0 MAKE IT 1
*/
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;
    }
};