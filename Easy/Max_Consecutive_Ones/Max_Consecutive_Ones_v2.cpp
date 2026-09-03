class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int maxi=0;
        for(auto it: nums){
            if(it==0) curr=0;
            else{
                curr+=it;
                maxi = max(maxi,curr);
            }
        }
        return maxi;
    }
};