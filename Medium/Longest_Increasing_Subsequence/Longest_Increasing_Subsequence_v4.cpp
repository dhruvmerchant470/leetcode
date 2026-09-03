class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tmp;
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(tmp.back()<nums[i]) tmp.push_back(nums[i]);
            else{
                int index=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[index]=nums[i];
            }
        }
        return tmp.size();
    }

};