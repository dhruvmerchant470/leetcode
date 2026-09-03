class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.size()<=numRows) return s; 
        vector<string>mat(numRows);
        int n=s.size();
        int i=0;
        int row_index=0;
        bool dir=true;
        while(i<n){
            mat[row_index].push_back(s[i]);
            if(row_index==numRows-1) dir=false;
            if(row_index==0) dir=true;
            if(dir) row_index++;
            else row_index--;
            i++;
        }
        string ans="";
        for(auto &it: mat) ans+=it;
        return ans;
    }
};