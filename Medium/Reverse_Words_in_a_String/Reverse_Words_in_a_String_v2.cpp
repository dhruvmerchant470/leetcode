class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string word;
        stringstream ss(s);

        while(ss>>word){
            words.push_back(word);
        }

        string res="";
        for(int i=words.size()-1;i>=0;i--){
            res+=words[i];
            if(i!=0) res+=" ";
        }
        return res;
    }
};