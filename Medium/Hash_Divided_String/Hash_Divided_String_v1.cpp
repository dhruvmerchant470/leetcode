class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int cnt=0;
        int index=1;
        for(int i=0;i<s.size();i++){
            cnt+=s[i]-'a';
            if(index%k==0){
                ans+=('a'+cnt%26);
                cnt=0;
            }
            index++;
        }
        return ans;
    }
};