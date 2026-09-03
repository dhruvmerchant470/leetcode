class Solution {
    set<pair<int, int>> memo, memo1;

public:
    void bfs(int x, int y, vector<vector<int>>& heights,
             set<pair<int, int>>& memo, set<pair<int, int>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        vector<int> d = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({x, y});
        visited.insert({x, y});
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            memo.insert({cx, cy});
            for (int i = 0; i < 4; i++) {
                int new_x = cx + d[i];
                int new_y = cy + d[i + 1];
                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n &&
                    visited.find({new_x, new_y}) == visited.end() &&
                    heights[new_x][new_y] >= heights[cx][cy]) {
                    visited.insert({new_x, new_y});
                    q.push({new_x, new_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        set<pair<int, int>> memoP, memoA;
        set<pair<int, int>> visitedP, visitedA;

        for (int i = 0; i < m; ++i) {
            bfs(i, 0, heights, memoP, visitedP);     // Pacific Left
            bfs(i, n - 1, heights, memoA, visitedA); // Atlantic Right
        }
        for (int j = 0; j < n; ++j) {
            bfs(0, j, heights, memoP, visitedP);     // Pacific Top
            bfs(m - 1, j, heights, memoA, visitedA); // Atlantic Bottom
        }

        vector<vector<int>> ans;
        for (auto& cell : memoP) {
            if (memoA.count(cell)) {
                ans.push_back({cell.first, cell.second});
            }
        }
        return ans;
    }
};