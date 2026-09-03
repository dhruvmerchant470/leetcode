class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int row1 = x;
        int row2 = x+k-1;
        int col1 = y;
        int col2 = y+k-1;
        while(row1<row2){
            for(int i=col1;i<=col2;i++){
                int tmp = grid[row1][i];
                grid[row1][i]=grid[row2][i];
                grid[row2][i]=tmp;
            }
            row1++;
            row2--;
        }
        return grid;
    }
};