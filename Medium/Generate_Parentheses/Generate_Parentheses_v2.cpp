class Solution {
public:
    vector<string>res;
    void dfs(int l,int r,string s,int n){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(l<n) dfs(l+1,r,s+'(',n);
        if(r<l) dfs(l,r+1,s+')',n);
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,"",n);
        return res;
    }
};