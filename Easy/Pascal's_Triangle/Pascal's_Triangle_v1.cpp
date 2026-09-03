class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return {};
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        vector<vector<int>>ans(numRows);
        ans[0]={1};
        ans[1]={1,1};
        for(int i=2;i<numRows;i++){
            vector<int>tmp;
            tmp.push_back(1);
            for(int j=1;j<i;j++){
                tmp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            tmp.push_back(1);
            ans[i]=tmp;
        }
        return ans;
    }
};