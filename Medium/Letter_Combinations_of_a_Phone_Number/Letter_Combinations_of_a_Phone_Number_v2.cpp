class Solution {
public:
    std::map<char, std::vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string>res;
    void helper(string tmp,string &digits, int index){
        if(index==digits.size()) {
            res.push_back(tmp);
            return;
        }
        if(digits[index]=='2'){
            for(int i=0;i<3;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='3'){
            for(int i=0;i<3;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='4'){
            for(int i=0;i<3;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='5'){
            for(int i=0;i<3;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='6'){
            for(int i=0;i<3;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='7'){
            for(int i=0;i<4;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='8'){
            for(int i=0;i<3;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
        if(digits[index]=='9'){
            for(int i=0;i<4;i++){
                tmp.push_back(mp[digits[index]][i]);
                helper(tmp,digits,index+1);
                tmp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        helper("",digits,0);
        return res;
    }
};