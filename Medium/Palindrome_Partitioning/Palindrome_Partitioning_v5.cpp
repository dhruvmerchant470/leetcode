class Solution {
public:
    void recurse(vector<vector<string>>&ans,int index, string s,vector<string>tmp){
        if(index>=s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i = index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                tmp.push_back(s.substr(index,i-index+1));
                recurse(ans,i+1,s,tmp);
                tmp.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int l,int h){
        while(l<=h){
            if(s[l]!=s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        recurse(ans,0,s,{});
        return ans;
    }
};