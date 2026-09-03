class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;int ans;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=1;
            }
            else ans=nums[i];
        }
        return ans;
    }
};