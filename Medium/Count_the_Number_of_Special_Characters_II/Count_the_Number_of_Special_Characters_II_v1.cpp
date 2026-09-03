class Solution {
public:
    int numberOfSpecialChars(string words) {
        vector<int>lower(26,-1);
        vector<int>upper(26,-1);
        for(int i=0;i<words.size();i++){
            if(words[i]>='a' && words[i]<='z'){
                int index = words[i]-'a';
                lower[index]=i;
            }
            else if(words[i]>='A' && words[i]<='Z'){
                int index = words[i]-'A';
                if(upper[index]==-1) upper[index]=i;
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && upper[i]!=-1 && lower[i]<upper[i]) cnt++;
        }
        return cnt;
    }
};