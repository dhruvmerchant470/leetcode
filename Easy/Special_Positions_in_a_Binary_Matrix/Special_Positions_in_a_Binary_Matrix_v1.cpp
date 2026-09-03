class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    bool flag = true;
                    for(int k=0;k<m;k++){
                        if(k==i) continue;
                        if(mat[k][j]==1){
                            flag = false;
                            break;
                        }
                    }
                    for(int k=0;k<n;k++){
                        if(k==j) continue;
                        if(mat[i][k]==1){
                            flag = false;
                            break;
                        }
                    }
                    if(flag) cnt++;
                }
            }
        }
        return cnt;

    }
};