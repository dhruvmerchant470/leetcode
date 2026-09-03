class Solution {
public:
    bool isValid(string s1) {
        stack<int>s;
        for(auto ch: s1){
            if(ch=='{' || ch=='(' || ch=='[') s.push(ch);
            else{
                if(s.empty()) return false;
                if(ch=='}' && s.top()=='{') s.pop();
                else if(ch==')' && s.top()=='(') s.pop();
                else if(ch==']' && s.top()=='[') s.pop();
                else return false;
            }
        }
        if(s.empty()) return 1;
        else return 0;
    }
};