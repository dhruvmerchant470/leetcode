class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto it: s){
            if(it>='a' && it<='z'){
                ans.push_back(it);
            }else if(it=='*' && ans.size()>0){
                ans.pop_back();
            }else if(it=='%'){
                reverse(ans.begin(),ans.end());
            }else if(it=='#'){
                ans+=ans;
            }
        }
        return ans;
    }
};