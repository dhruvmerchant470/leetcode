class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                             {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans=mp[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X')) ans-=mp[s[i]];
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')) ans-=mp[s[i]];
            else if(s[i]=='C' && (s[i+1]=='D'||s[i+1]=='M')) ans-=mp[s[i]];
            else ans+=mp[s[i]];
        }
        return ans;
    }
};