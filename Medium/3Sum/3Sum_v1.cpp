class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            if(i==0||nums[i-1]!=nums[i])
            {
                int j=i+1,k=n-1;
                while(j<k){
                int sum=nums[j]+nums[k]+a;
                if(sum>0) k--;
                else if(sum<0) j++;
                else
                {
                    vector<int>tmp{a,nums[j],nums[k]};
                    ans.push_back(tmp);
                    while(j<k&&nums[j]==nums[j+1]) j++;
                    while(j<k&&nums[k]==nums[k-1]) k--;
                    j++;k--;
                }
                }
            }
        }
    return ans;
    }
};