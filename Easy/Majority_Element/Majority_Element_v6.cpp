class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int majority=0;
        for(auto &it: nums){
            if(majority==0) res = it;
            if(res==it) majority++;
            else majority--;
            
        }
        return res;
    }
};