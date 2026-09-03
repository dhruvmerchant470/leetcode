class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int maxi = 1;
        for(auto it: s){
            if(s.find(it-1)==s.end()){
                int len=1;
                while(s.find(it+len)!=s.end()) len++;
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};