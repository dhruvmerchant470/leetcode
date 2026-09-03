class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        int n=s.size();
        unordered_map<int,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1 && l<r){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};