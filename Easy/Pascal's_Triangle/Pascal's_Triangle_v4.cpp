class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        vector<vector<int>>ans;
        ans.push_back({{1}});
        ans.push_back({{1,1}});
        for(int i=2;i<numRows;i++){
            vector<int>tmp;
            tmp.push_back(1);
            vector<int>prev = ans[i-1];
            for(int j=0;j<prev.size()-1;j++){
                tmp.push_back(prev[j]+prev[j+1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};