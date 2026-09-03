class Solution {
public:
    vector<int> d = {-1, 0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board, int x, int y, int index,
             string& word) {
        if (index == word.size())
            return true;
        char tmp = board[x][y];
        board[x][y] = '\0';

        // cout<<index<<endl;
        // cout<<x<<" "<<y<<endl;
        for (int i = 0; i < 4; i++) {
            int new_x = x + d[i];
            int new_y = y + d[i + 1];
            if (new_x >= 0 && new_y >= 0 && new_x < board.size() &&
                new_y < board[0].size() && board[new_x][new_y] == word[index]) {
                if (dfs(board, new_x, new_y, index + 1, word))
                    return true;
            }
        }
        board[x][y] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board[0].size();
        int m = board.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    // vector<vector<int>>visited(m,vector<int>(n,0));
                    if (dfs(board, i, j, 1, word))
                        return true;
                }
            }
        }
        return false;
    }
};