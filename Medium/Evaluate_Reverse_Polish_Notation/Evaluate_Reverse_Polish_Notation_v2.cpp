class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int index=0;
        while(index<tokens.size()){
            if(tokens[index]=="+"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(a+b);
            }
            else if(tokens[index]=="-"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(b-a);
            }
            else if(tokens[index]=="*"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(a*b);
            }
            else if(tokens[index]=="/"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(b/a);
            }
            else s.push(stoi(tokens[index]));
            index++;
        }
        return s.top();
    }
};