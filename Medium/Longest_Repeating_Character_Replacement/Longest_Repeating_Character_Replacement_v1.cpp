class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0,r=0,maxi=0;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            maxi=max(maxi,mp[s[r]]);
            while((r-l+1)-maxi>k){
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return n-l;
    }
};