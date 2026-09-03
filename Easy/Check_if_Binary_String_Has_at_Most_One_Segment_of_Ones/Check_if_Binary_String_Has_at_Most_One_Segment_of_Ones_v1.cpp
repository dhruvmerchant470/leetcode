class Solution {
public:
    bool checkOnesSegment(string s) {
        bool contains=false;
        for(int i=0;i<s.size();i++){
            if(contains && s[i]=='1') return false;
            while(s[i]=='1'){
                i++;
                contains = true;
            }
        }
        return contains;
    }
};