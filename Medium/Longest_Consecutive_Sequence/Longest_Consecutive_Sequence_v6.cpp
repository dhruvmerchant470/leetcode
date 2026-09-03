class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(),nums.end());
        int maxi=0;
        for(int num: numSet){
            if(numSet.find(num-1)==numSet.end()){
                int len=1;
                while(numSet.find(num+len)!=numSet.end()){
                    len++;
                }   
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};