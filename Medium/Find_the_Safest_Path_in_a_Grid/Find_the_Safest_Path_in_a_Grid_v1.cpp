class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int ans = INT_MAX;
    bool isPossible(int x, int y, vector<vector<bool>>& visited) {
        if (x >= 0 && y >= 0 && x < visited.size() && y < visited[0].size() &&
            !visited[x][y])
            return true;
        else
            return false;
    }
    
    void dijntra(vector<vector<int>>& new_grid) {
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({new_grid[0][0], {0, 0}});
        vector<vector<bool>> visited(new_grid.size(),
                                     vector<bool>(new_grid[0].size(), false));
        visited[0][0]=true;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            // visited[top.second.first][top.second.second] = true;
            ans = min(ans, top.first);
            if (top.second.first == new_grid.size() - 1 &&
                top.second.second == new_grid[0].size() - 1)
                return;
            for (int i = 0; i < dir.size() - 1; i++) {
                int new_x = top.second.first + dir[i];
                int new_y = top.second.second + dir[i + 1];
                if (isPossible(new_x, new_y, visited))
                {
                    visited[new_x][new_y]=true;
                    pq.push({new_grid[new_x][new_y], {new_x, new_y}});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<pair<int, int>> thief_coords;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    thief_coords.push_back({i, j});
            }
        }
        queue<pair<int, int>> q;
        vector<vector<int>> new_grid(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    new_grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    new_grid[nx][ny] == INT_MAX) {

                    new_grid[nx][ny] = new_grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // print(new_grid);
        dijntra(new_grid);
        return ans;
    }
};