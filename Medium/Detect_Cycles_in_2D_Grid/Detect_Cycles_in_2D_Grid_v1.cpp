class Solution {
public:
    bool isCondition(int x, int y, vector<vector<char>>&grid,
                     vector<vector<bool>>& visited,int p_x,int p_y) {
        if (x >= 0 && y >= 0 && x < visited.size() && y < visited[0].size() &&
            visited[x][y] == 0 && grid[x][y]==grid[p_x][p_y]) {
            return true;
        }
        return false;
    }
    bool secCondition(int n_x, int n_y, int p_x, int p_y, int pp_x, int pp_y,
                      vector<vector<char>>& grid,
                      vector<vector<bool>>& visited) {
        if (n_x >= 0 && n_y >= 0 && n_x < visited.size() && n_y < visited[0].size() &&
            visited[n_x][n_y] && grid[n_x][n_y] == grid[p_x][p_y] &&
            !(pp_x == n_x && pp_y == n_y))
            return true;
        else
            return false;
    }
    bool dfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int x,
             int y, int parent_x, int parent_y) {
        visited[x][y] = 1;
        int new_x = x + 1, new_y = y;
        if (isCondition(new_x, new_y, grid, visited,x,y)) {
            bool ans = dfs(visited, grid, new_x, new_y, x, y);
            if (ans)
                return ans;
        } else if (secCondition(new_x, new_y, x, y, parent_x, parent_y, grid,
                                visited)) {
            return true;
        }

        new_x = x - 1, new_y = y;
        if (isCondition(new_x, new_y, grid,
                        visited,x,y)) {
            bool ans = dfs(visited, grid, new_x, new_y, x, y);
            if (ans)
                return ans;
        } else if (secCondition(new_x, new_y, x, y, parent_x, parent_y, grid,
                                visited)) {
            return true;
        }

        new_x = x, new_y = y + 1;
        if (isCondition(new_x, new_y, grid,
                        visited,x,y)) {
            bool ans = dfs(visited, grid, new_x, new_y, x, y);
            if (ans)
                return ans;
        } else if (secCondition(new_x, new_y, x, y, parent_x, parent_y, grid,
                                visited)) {
            return true;
        }

        new_x = x, new_y = y - 1;
        if (isCondition(new_x, new_y, grid,
                        visited,x,y)) {
            bool ans = dfs(visited, grid, new_x, new_y, x, y);
            if (ans)
                return ans;
        } else if (secCondition(new_x, new_y, x, y, parent_x, parent_y, grid,
                                visited)) {
            return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    bool ans=dfs(visited, grid, i, j, -1, -1);
                    if(ans) return ans;
                }
            }
        }
        return false;
    }
};