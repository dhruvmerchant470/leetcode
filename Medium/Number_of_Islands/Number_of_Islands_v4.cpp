class Solution {
public:
    vector<int>dir={-1,0,1,0,-1};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>&visited, int x, int y){
        visited[x][y] = true;
        for(int i=0;i<dir.size()-1;i++){
            int new_x = x+dir[i];
            int new_y = y+dir[i+1];
            if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y]=='1' && !visited[new_x][new_y]){
                dfs(grid,visited,new_x,new_y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,visited,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};