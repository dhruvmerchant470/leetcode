class Solution {
public:
    bool check(vector<vector<char>>&grid,int x,int y){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1') return true;
        else return false;
    }
    void bfs(vector<vector<char>>&grid,int x,int y){
        queue<pair<int,int>>q;
        vector<int>dir={-1,0,1,0,-1};
        q.push({x,y});
        grid[x][y]='0';
        while(!q.empty()){
            auto top=q.front();
            
            q.pop();
            for(auto i=0;i<dir.size()-1;i++){
                int new_x=top.first+dir[i];
                int new_y=top.second+dir[i+1];
                if(check(grid,new_x,new_y)){
                    grid[new_x][new_y]='0';
                    q.push({new_x,new_y});
                }
            }
        }

    }

    void dfs(vector<vector<char>>&grid, int x,int y){
        grid[x][y]='0';
        vector<int>dir={-1,0,1,0,-1};
        for(int i=0;i<dir.size()-1;i++){
            int new_x=x+dir[i];
            int new_y=y+dir[i+1];
            if(check(grid,new_x,new_y)){
                dfs(grid,new_x,new_y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};