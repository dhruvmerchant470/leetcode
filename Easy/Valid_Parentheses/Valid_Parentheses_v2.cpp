class Solution {
public:
    bool isValid(string s1) {
        stack<char> s;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
                s.push(s1[i]);
            else {
                if (!s.empty() && s1[i] == ')' && s.top() == '(')
                    s.pop();

                else if (!s.empty() && s1[i] == ']' && s.top() == '[')
                    s.pop();

                else if (!s.empty() && s1[i] == '}' && s.top() == '{')
                    s.pop();
                else
                    return false;
            }
        }
        if(s.empty()) return true;
        else return false;
    }
};