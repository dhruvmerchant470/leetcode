class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>A(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) A[i][j] = matrix[i][j];
                else A[i][j] = A[i][j-1] + matrix[i][j];
            }
        }
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                int cur = 0;
                unordered_map<int,int>mp;
                mp[cur]=1;
                for(int k=0;k<n;k++){
                    cur+=(A[k][j] - (i>0?A[k][i-1]:0));
                    res+=mp[cur-target];
                    mp[cur]+=1;
                }
            }
        }
        return res;
    }
};