class Solution {
public:
    void solve(int index,string s,vector<string>tmp,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(tmp);
            // tmp.clear();
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPal(s,index,i)){
                tmp.push_back(s.substr(index,i-index+1));
                solve(i+1,s,tmp,ans);
                tmp.pop_back();
            }
        }
    }

    bool isPal(string s,int i,int j){
        while(i<=j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        solve(0,s,{},ans);
        return ans;
    }
};