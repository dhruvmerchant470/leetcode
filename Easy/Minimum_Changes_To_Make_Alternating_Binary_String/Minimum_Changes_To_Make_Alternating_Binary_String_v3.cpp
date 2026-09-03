class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=(s[i]&1)^(i&1);
        }
        return min(ans,(int)s.size()-ans);
    }
};