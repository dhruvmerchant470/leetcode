class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int a=nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
             for(int j=i+1;j<n;j++){
                int b=nums[j];
                if(j==i+1 || nums[j]!=nums[j-1]){
                    int s=j+1;
                    int e=n-1;
                    while(s<e){
                        long long sum = 1LL * a + b + nums[s] + nums[e];
                        if (sum > (long long)target) e--;
                        else if (sum < (long long)target) s++;
                        else{
                            vector<int>tmp={a,b,nums[s],nums[e]};
                            ans.push_back(tmp);
                            while(s<e&&nums[s]==nums[s+1]) s++;
                            while(s<e&& nums[e]==nums[e-1]) e--;
                            s++;
                            e--;
                        }
                    }
                }
            }
        }
        // vector<vector<int>>a1;
        // for(auto it:ans){
        //     a1.push_back(it);
        // }
        return ans;
    }
};