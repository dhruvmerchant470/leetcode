class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                        (board[ni][nj] == 1 || board[ni][nj] == -1))
                        live++;
                }

                // Mark the cell to transition
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = -1;  // 1 -> 0
                } else if (board[i][j] == 0 && live == 3) {
                    board[i][j] = 2;   // 0 -> 1
                }
            }
        }

        // Finalize state
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
    }
};
