class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        int l=0,r=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(r<n){
            while(nums[r]-nums[l]>1 && l<r){
                l++;
            }
            if(r>l && nums[r]-nums[l]==1) ans=max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};