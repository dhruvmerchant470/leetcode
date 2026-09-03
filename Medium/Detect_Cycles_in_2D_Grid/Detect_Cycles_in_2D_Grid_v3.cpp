class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x,
             int y, int p_x, int p_y, char c) {
        visited[x][y] = true;
        // cout<<x<<" "<<y<<" "<<p_x<<" "<<p_y<<endl;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() &&
                grid[nx][ny] == c) {
                if (!visited[nx][ny]) {
                    if (dfs(grid, visited, nx, ny, x, y, c))
                        return true;
                } else if (!(nx==p_x && ny==p_y)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};