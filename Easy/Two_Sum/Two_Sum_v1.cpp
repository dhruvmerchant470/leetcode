class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum=0;
        vector<int> a(2);
        for(int i=0;i<nums.size();i++){
            sum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==target){
                    a[0]=i;a[1]=j;
                }
                sum-=nums[j];
            }
        }
        return a;
    }
};