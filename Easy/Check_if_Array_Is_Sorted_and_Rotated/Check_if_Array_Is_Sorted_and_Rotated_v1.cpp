class Solution {
public:
    bool check(vector<int>& nums) {
        int ans=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {ans++;}
            
        }
        if(nums[0]<nums[nums.size()-1])
        {
            ans++;
        }
        if(ans<=1) return true;
        else return false;
    }
};