class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(vector<vector<int>>&grid, int x, int y){
        grid[x][y]=1;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0){
                dfs(grid,nx,ny);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(grid[i][0] == 0) dfs(grid,i,0);
            if(grid[i][m-1]==0) dfs(grid,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0) dfs(grid,0,i);
            if(grid[n-1][i]==0) dfs(grid,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt+=1;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};