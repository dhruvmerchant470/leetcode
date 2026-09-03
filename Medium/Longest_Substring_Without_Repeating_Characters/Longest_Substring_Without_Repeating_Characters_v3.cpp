class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int ans=0;
        map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(l<r && mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
