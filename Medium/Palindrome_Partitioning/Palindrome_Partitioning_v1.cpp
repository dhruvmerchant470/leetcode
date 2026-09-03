class Solution {
public:
    void recursive(vector<vector<string>>&ans,vector<string>tmp,string s,int index){
        if(index==s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                tmp.push_back(s.substr(index,i-index+1));
                recursive(ans,tmp,s,i+1);
                tmp.pop_back();
            }
        }
    }
    bool isPalindrome(string s1,int s,int e){
        while(s<=e){
            if(s1[s++]!=s1[e--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        recursive(ans,{},s,0);
        return ans;
    }
};