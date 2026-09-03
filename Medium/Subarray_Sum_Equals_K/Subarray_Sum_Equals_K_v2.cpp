class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int sum=0;
        map<int,int>mp;
        mp[0]=1;
        for(auto n:nums){
            sum+=n;
            if(mp.find(sum-k)!=mp.end()) 
            {
                res+=mp[sum-k];
            }
            if(mp.find(sum)!=mp.end()){
                mp[sum]+=1;
            }
            else{
                mp[sum]=1;
            }
            
        }
        return res;
    }
};