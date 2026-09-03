class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(vector<vector<int>>&land, vector<vector<bool>>&visited, int x, int y, int &mx, int &my){
        visited[x][y] = true;
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<land.size() && ny<land[0].size() && land[nx][ny]==1 &&
                !visited[nx][ny]){
                    mx = max(mx,nx);
                    my = max(my,ny);
                    dfs(land,visited,nx,ny,mx,my);
                }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && land[i][j]==1){
                    int mx = i;
                    int my = j;
                    dfs(land,visited,i,j,mx,my);
                    ans.push_back({i,j,mx,my});
                }
            }
        }
        return ans;
    }
};