class Solution {
public:
    bool isValid(string s1) {
        stack<char>s;
        for(int i=0;i<s1.length();i++)
        {
            char ch=s1[i];
            if(s1[i]=='{'||s1[i]=='('||ch=='[') s.push(ch);
            else 
            {
                if(ch=='}')
                {
                    if(!s.empty()&&s.top()=='{') s.pop();
                    else return false;
                }

                if(ch==')') {
                    if(!s.empty()&&s.top()=='(') s.pop();
                    else return false;
                }
                if(ch==']') {
                    if(!s.empty()&&s.top()=='[') s.pop();
                    else return false;
                }
            }
        }
        if(s.empty()) return true;
        else return false;
    }
};