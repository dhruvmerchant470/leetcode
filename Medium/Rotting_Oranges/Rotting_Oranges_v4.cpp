class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // do a level order traversal;
        queue<pair<int, int>> q;
        vector<int> dir = {-1, 0, 1, 0, -1}; // UP,LEFT,DOWN,RIGHT
        int level = -1;
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            int size = q.size();
            level++;
            while (size--) {
                auto f = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int new_x = f.first + dir[i];
                    int new_y = f.second + dir[i + 1];
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m &&
                        grid[new_x][new_y] == 1) {
                        q.push({new_x, new_y});
                        grid[new_x][new_y]=2;
                        fresh--;
                    }
                }
            }
        }

        if(fresh>0) return -1;
        if(level==-1) return 0;
        return level;
    }
};