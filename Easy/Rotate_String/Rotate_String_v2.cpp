class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            if(rotate(s,goal,i)){
                return true;
            }
        }
        return false;
    }
    bool rotate(string s,string g,int rot){
        for(int i=0;i<s.size();i++){
            if(s[i]!=g[(i+rot)%g.size()]){
                return false;
            }
        }
        return true;
    }
};