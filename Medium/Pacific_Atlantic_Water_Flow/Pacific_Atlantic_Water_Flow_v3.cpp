class Solution {
    vector<int> d = {1, 0, -1, 0, 1};

public:
    void bfs(int x, int y, vector<vector<int>>& heights,
             set<pair<int, int>>& memo, set<pair<int, int>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visited.insert({x, y});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            memo.insert({top.first, top.second});
            for (int i = 0; i < 4; i++) {
                int new_x = d[i] + top.first;
                int new_y = d[i + 1] + top.second;
                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n &&
                    (visited.find({new_x, new_y}) == visited.end()) &&
                    heights[new_x][new_y] >= heights[top.first][top.second]) {
                    q.push({new_x, new_y});
                    visited.insert({new_x, new_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights[0].size();
        int m = heights.size();
        vector<vector<int>> ans;
        set<pair<int, int>> visP, visA, memoP, memoA;
        for (int i = 0; i < n; i++) {
            bfs(0, i, heights, memoP, visP);
            bfs(m - 1, i, heights, memoA, visA);
        }
        for (int i = 0; i < m; i++) {
            bfs(i, 0, heights, memoP, visP);
            bfs(i, n - 1, heights, memoA, visA);
        }
        for (auto& cell : memoP) {
            if (memoA.count(cell)) {
                ans.push_back({cell.first, cell.second});
            }
        }
        return ans;
    }
};