class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxi=0;
        unordered_map<char,int>mp;
        int n=s.length();
        while(l<n&&r<n){
            mp[s[r]]+=1;
            while(mp[s[r]]>1 && l<n) {
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
