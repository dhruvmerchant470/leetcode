class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        int vowel=false,cons=false;
        set<char>s{'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<word.size();i++){
            if(!isalnum(word[i])) return false;
            else{
                if(s.find(word[i])!=s.end()) vowel=true;
                else if(word[i]<'0' || word[i]>'9') cons=true;
            }
        }
        // cout<<vowel<<" "<<cons<<endl;
        return vowel && cons;
    }
};