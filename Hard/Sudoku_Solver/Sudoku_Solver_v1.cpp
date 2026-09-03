class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        int n = board[0].size();
        int m = board.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isPossible(board,i,j,c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isPossible(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++) if(board[row][i]==c) return false;
        for(int i=0;i<9;i++) if(board[i][col]==c) return false;
        for(int i=0;i<9;i++){
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};