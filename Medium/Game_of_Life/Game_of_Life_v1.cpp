class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    bool check(vector<vector<int>>& board, int t, int x, int y) {

        int no_one = 0;
        for (int i = 0; i < 8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_y >= 0 && new_x < board.size() &&
                new_y < board[0].size()) {
                if (board[new_x][new_y] == 1)
                    no_one += 1;
            }
        }
        if (t == 1) {
            if (no_one < 2 || no_one > 3)
                return true;
            else
                return false;
        } else {
            if (no_one == 3)
                return true;
            else
                return false;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (check(board, board[i][j], i, j))
                    vec.push_back({i, j});
            }
        }
        for (int i = 0; i < vec.size(); i++)
            board[vec[i].first][vec[i].second] =
                !board[vec[i].first][vec[i].second];
    }
};