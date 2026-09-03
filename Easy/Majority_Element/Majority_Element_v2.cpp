class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        int majority=0;
        for (auto n: nums){
            if(majority==0) res=n;
            if(n==res) majority++;
            else majority--;
            
            
        }
        return res;
    }
};