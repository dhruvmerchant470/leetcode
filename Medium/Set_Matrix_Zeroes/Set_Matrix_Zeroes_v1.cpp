class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>rows;
        set<int>cols;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto it=rows.begin();it!=rows.end();it++){
            for(int j=0;j<n;j++) matrix[*it][j]=0;
        }
        for(auto it=cols.begin();it!=cols.end();it++){
            for(int j=0;j<m;j++) matrix[j][*it]=0;
        }
    }
};