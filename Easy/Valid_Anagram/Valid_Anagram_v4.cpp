class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v(26,0);
        for(char &c:s){
            v[c-'a']+=1;
        }
        for(char &c:t){
            v[c-'a']-=1;
        }
        for(auto &it: v){
            if(it!=0) return false;
        }
        return true;
    }
};