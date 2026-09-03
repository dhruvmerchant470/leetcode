class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxi = INT_MIN;
        vector<int>pref(nums.size());
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxi = max(maxi,curr);
            curr = max(0,curr);
            pref[i] = maxi;
        }
        // for(int i: pref) cout<<i<<" ";
        cout<<endl;
        return maxi;
    }
};