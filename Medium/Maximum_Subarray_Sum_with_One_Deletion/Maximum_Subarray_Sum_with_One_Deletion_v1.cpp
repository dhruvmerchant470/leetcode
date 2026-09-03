class Solution {
public:
    int maximumSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int curr = 0;
        int curr2 = 0;
        int maxi = INT_MIN;
        int maxi2 = INT_MIN;
        vector<int>pref(nums.size());
        vector<int>suff(nums.size());
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            curr2+=nums[n-i-1];
            maxi = max(maxi,curr);
            maxi2 = max(maxi2,curr2);
            suff[n-i-1] = curr2; 
            pref[i] = curr;
            curr = max(0,curr);
            curr2 = max(0,curr2);
        }
        int maxi3 = INT_MIN;
        // for(int i: pref) cout<<i<<" ";
        // cout<<endl;
        // for(int i: suff) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(i==0) maxi3 = max(maxi3,suff[i+1]);
            else if(i==n-1) maxi3 = max(maxi3,pref[i-1]);
            else maxi3 = max({maxi3,pref[i-1]+suff[i+1]});
        }
        return max({maxi,maxi2,maxi3});
    }
};