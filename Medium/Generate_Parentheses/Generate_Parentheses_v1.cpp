class Solution {
public:
    vector<string>all;
    void generate(int n,string tmp){
        if(tmp.size()==n){
            all.push_back(tmp);
            return;
        }
        tmp.push_back('(');
        generate(n,tmp);
        tmp.pop_back();
        tmp.push_back(')');
        generate(n,tmp);
        tmp.pop_back();
    }
    bool check(string &tmp){
        stack<char>s;
        for(auto ch: tmp){
            if(ch=='(') s.push('(');
            else{
                if(s.empty() || s.top()!='(') return false;
                else s.pop();
            }
        }
        return s.empty();
    }
    vector<string> generateParenthesis(int n) {
        generate(2*n,"");
        vector<string>ans;
        for(string &tmp: all){
            if(check(tmp)) ans.push_back(tmp);
        }
        return ans;
    }
};