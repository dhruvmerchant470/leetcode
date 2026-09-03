class Solution {
public:
    vector<vector<string>>res;
    void help(int index,string s,vector<string> tmp){
        if(index==s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=index;i<s.size();i++){
            string t=s.substr(index,i-index+1);
            if(isPal(t)){
                tmp.push_back(t);
                help(i+1,s,tmp);
                tmp.pop_back();
            }
        }
    }
    bool isPal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        help(0,s,{});
        return res;
    }
};