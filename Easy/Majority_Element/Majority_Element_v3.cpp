class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n1=nums.size()/2;
        int maj=nums[0];
        int cnt=0;
        for(auto elt: nums){
            if(cnt==0) maj=elt;
            if(elt==maj){
                cnt++;
            }
            else cnt--;
        }
        return maj;
    }
};