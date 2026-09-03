class Solution {
    
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        vector<pair<int,int>>tmp;
        for(int i=0;i<nums.size();i++){
            tmp.push_back({nums[i],i});
        }
        sort(tmp.rbegin(),tmp.rend());
        for(int i=0;i<k;i++){
            ans.push_back(tmp[i].second);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++) ans[i]=nums[ans[i]];
        return ans;
    }
};