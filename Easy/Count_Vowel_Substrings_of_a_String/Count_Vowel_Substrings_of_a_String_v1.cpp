class Solution {
public:

    int countVowelSubstrings(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
                if(word[j]!='a' && word[j]!='e' && word[j]!='i'
                && word[j]!='o' && word[j]!='u') break;
                mp[word[j]]++;
                if(mp.size()>=5) cnt++;
            }
        }
        return cnt;
    }
};