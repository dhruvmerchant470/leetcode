class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int prev_i=0;
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+prev_i,s.begin()+i);
                prev_i=i+1;
            }
        }
        reverse(s.begin()+prev_i,s.begin()+i);
        int index=0;
        while(s[index]==' '){
            s.erase(s.begin()+index);
        }
        
        while(s[s.size()-1]==' '){
            s.erase(prev(s.end()));
        }

        for(index=0;index<s.size();index++){
            while(index+1<s.size() && s[index]==' ' && s[index+1]==' ') s.erase(s.begin()+index);
        }
        return s;
    }
};