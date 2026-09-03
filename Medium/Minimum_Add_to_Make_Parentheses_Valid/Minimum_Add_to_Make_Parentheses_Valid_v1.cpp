class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>s1;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') s1.push('(');
            else if(s[i]==')'){
                if(!s1.empty()&&s1.top()=='(') s1.pop();
                else s1.push(')');
            }
        }
        return s1.size();
    }
};