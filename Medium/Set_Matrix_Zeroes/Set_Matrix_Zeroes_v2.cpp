class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row=false;
        bool first_col=false;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    if(i==0)
                    first_row=true;
                    if(j==0)
                    first_col=true;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(first_row){
            for(int j=0;j<n;j++) matrix[0][j]=0;
        }
        if(first_col){
            for(int j=0;j<m;j++) matrix[j][0]=0;
        }
    }
};