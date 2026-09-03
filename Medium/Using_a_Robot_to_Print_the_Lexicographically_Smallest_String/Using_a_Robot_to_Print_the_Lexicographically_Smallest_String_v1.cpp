class Solution {
public:
    string robotWithString(string s) {
        map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++) mp[s[i]]+=1;
        stack<char>s1;
        string ans="";
        for(int i=0;i<n;i++){
            s1.push(s[i]);
            mp[s[i]]--;
            if(mp[s[i]]==0){
                auto it=mp.find(s[i]);
                if(it!=mp.end()) mp.erase(it);
            }
            while(!s1.empty() && s1.top()<=mp.begin()->first){
                ans+=s1.top();
                s1.pop();
            }
        }
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        return ans;
    }
};