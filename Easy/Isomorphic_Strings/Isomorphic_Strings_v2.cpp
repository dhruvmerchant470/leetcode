class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char>mp;
        unordered_map<char,char>mp1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=t[i];
            }
            else{
                if(t[i]!=mp[s[i]]) return false;
            }
            if(mp1.find(t[i])==mp1.end()){
                mp1[t[i]]=s[i];
            }
            else{
                if(s[i]!=mp1[t[i]]) return false;
            }
        }
        return true;
    }
};