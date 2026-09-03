class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r<(int)s.size()){
            mp[s[r]]++;
            while(mp[s[r]]>1 && l<r){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};