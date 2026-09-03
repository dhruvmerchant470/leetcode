class Solution {
public:
    vector<int>dir = {-1,0,1,0,-1};
    bool dfs(vector<vector<int>>&grid,vector<vector<bool>>&visited, int x, int y, int health,vector<vector<int>>&best){
        int n = grid.size();
        int m = grid[0].size();
        if(best[x][y]>=health){
            return false;
        }
        visited[x][y]=true;
        // cout<<x<<" "<<y<<endl;
        best[x][y]=health;
        if(x==n-1 && y==m-1 && health>0) return true;
        for(int i=0;i<dir.size()-1;i++){
            int new_x = x+dir[i];
            int new_y = y+dir[i+1];
            // cout<<new_x<<" "<<new_y<<";";
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !visited[new_x][new_y] && health>grid[new_x][new_y]){
                if(dfs(grid,visited,new_x,new_y,health-grid[new_x][new_y],best)) return true;
            }
        }
        visited[x][y]=false;
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>best(n,vector<int>(m,-1)); //this is the new thing I learned
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        return dfs(grid,visited,0,0,health-grid[0][0],best);
    }
};