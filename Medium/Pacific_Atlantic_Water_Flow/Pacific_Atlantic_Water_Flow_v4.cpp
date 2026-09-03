class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<bool>>bfs(vector<vector<int>>& heights, bool flag){
        queue<pair<int,int>>q;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        if(flag){
            for(int i=0;i<n;i++){
                q.push({i,0});
            }
            for(int j=1;j<m;j++){
                q.push({0,j});
            }
        }else{
            for(int i=0;i<n;i++){
                q.push({i,m-1});
            }
            for(int j=0;j<m-1;j++){
                q.push({n-1,j});
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(visited[x][y]) continue;
            visited[x][y]=true;
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && heights[nx][ny]>=heights[x][y]){
                    q.push({nx,ny});
                }
            }
        }

        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        vector<vector<bool>>visited1 = bfs(heights,false);
        vector<vector<bool>>visited2 = bfs(heights,true);
        for(int i=0;i<visited1.size();i++){
            for(int j=0;j<visited1[0].size();j++){
                if(visited1[i][j] && visited2[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};