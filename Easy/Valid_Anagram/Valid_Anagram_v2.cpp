class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()) mp[s[i]]=1;
            else mp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])==mp.end()) return false;
            mp[t[i]]--;
            if(mp[t[i]]==0) mp.erase(t[i]);
        }
        if(mp.size()==0) return true;
        else return false;
    }
};