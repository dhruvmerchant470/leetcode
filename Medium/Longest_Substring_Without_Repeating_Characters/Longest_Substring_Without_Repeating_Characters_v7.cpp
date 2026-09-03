class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(right<s.size()){
            mp[s[right]]++;
            while(mp[s[right]]>1 && left<right){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};