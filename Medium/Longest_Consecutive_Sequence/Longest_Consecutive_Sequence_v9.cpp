class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.size()<=1) return nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int maxi = 0;
        for(auto num : s){
            int len = 1;
            if(s.find(num-1)==s.end()){
                while(s.find(num+len)!=s.end()) len+=1;
            }
            maxi = max(maxi,len);
        }
        return maxi;
    }
};