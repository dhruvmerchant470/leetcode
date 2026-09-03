class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string tmp="";
            for(int i=0;i<word.size();i++){
                if(word[i]=='z') tmp.push_back('a');
                tmp.push_back(word[i]+1);
            }
            word+=tmp;
        }
        return word[k-1];
    }
};