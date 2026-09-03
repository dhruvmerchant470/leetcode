class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(ll i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            ll a  = nums[i];
            for(ll j=i+1;j<nums.size();j++){
                ll b=nums[j];
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                ll k = j+1,l=nums.size()-1;
                while(k<l){
                    ll sum = 1LL*a+b+nums[k]+nums[l];
                    if(sum==target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k+1]==nums[k]) k++;
                        while(k<l && nums[l-1]==nums[l]) l--;
                        k++;
                        l--;
                    }
                    else if(sum>target) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};