class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int>mp;
        for(auto ch: t) mp[ch]++;
        int req_chars=t.length();
        int start=0;
        int index[2]={0,INT_MAX};
        for(int end=0;end<s.size();end++){
            if(mp.find(s[end])!=mp.end() && mp[s[end]]>0){
                req_chars--;
            }
            mp[s[end]]--;
            if(req_chars==0){
                while(true){
                    char ch=s[start];
                    if(mp.find(ch)!=mp.end() && mp[ch]==0) break;
                    mp[ch]++;
                    start++;
                }
                if(end-start<index[1]-index[0]){
                    index[1]=end;
                    index[0]=start;
                }
                mp[s[start]]++;
                start++;
                req_chars++;
            }
        }
        cout<<index[0]<<" "<<index[1]<<endl;
        return index[1]==INT_MAX?"":s.substr(index[0],index[1]-index[0]+1);
        
    }
};