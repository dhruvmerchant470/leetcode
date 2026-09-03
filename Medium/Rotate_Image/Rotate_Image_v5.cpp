class Solution {
public:
    void print(vector<vector<int>>&matrix){
        int n = matrix[0].size();
        int m = matrix.size();
        for(int i=0 ; i<m ;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        for(int i=0 ; i<m ;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};