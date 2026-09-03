class Solution {
    set<pair<int,int>>memo;
public:
    bool bfs(int &x, int &y, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<int> d={1, 0, -1, 0, 1};
        // D L U R
        pair<bool, bool> ans = {0, 0};
        set<pair<int,int>>visited;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            visited.insert({top.first,top.second});
            if(memo.find({top.first,top.second})!=memo.end()) return true;
            if(top.first==0 || top.second==0) ans.first=1;
            if(top.first==m-1 || top.second==n-1) ans.second=1;
            if(ans.first && ans.second) return true;
            for (int i = 0; i < 4; i++) {
                int new_x = d[i] + top.first;
                int new_y = d[i + 1] + top.second;
                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n &&
                    (visited.find({new_x,new_y})==visited.end())&&
                    heights[new_x][new_y] <= heights[top.first][top.second]){
                        q.push({new_x,new_y});
                    }
            }
        }
        if(ans.first && ans.second) return true;
        else return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights[0].size();
        int m=heights.size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(bfs(i,j,heights)){
                    ans.push_back({i,j});
                    memo.insert({i,j});
                } 
            }
        }
        return ans;
    }
};