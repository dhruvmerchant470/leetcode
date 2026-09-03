class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int right=0;
        int left_far=0;
        int left_near=0;
        int res=0;
        map<int,int>mp;
        for(;right<nums.size();right++){
            if(mp.find(nums[right])!=mp.end()){
                mp[nums[right]]+=1;
            }
            else mp[nums[right]]=1;

            while(mp.size()>k){
                mp[nums[left_near]]-=1;
                if(mp[nums[left_near]]==0){
                    mp.erase(nums[left_near]);
                }
                left_near+=1;
                left_far=left_near;
            }

            while(mp[nums[left_near]]>1){
                mp[nums[left_near]]-=1;
                left_near+=1;
            }

            if(mp.size()==k){
                res+=1+left_near-left_far;
            }
        }
        return res;
    }
};