class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return {};
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        vector<vector<int>>ans(numRows);
        ans[0]={1};
        ans[1]={1,1};
        int col=3;
        for(int i=2;i<numRows;i++){
            vector<int>tmp(col);
            for(int j=0;j<col;j++){
                if (j-1<0) tmp[j]=ans[i-1][j];
                else if (j>=col-1) tmp[j]=ans[i-1][j-1];
                else tmp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
           
            ans[i]=tmp;
            col++;
        }
        return ans;
    }
};