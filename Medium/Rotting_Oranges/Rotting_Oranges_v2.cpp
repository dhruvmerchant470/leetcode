class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        vector<int>dir={1,0,-1,0,1};
        int fresh=0;
        int level=-1;
        int n=grid[0].size(),m=grid.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    
                } 
                if(grid[i][j]==1) fresh++;
            }
        }
        while(!q.empty()){
            int size=q.size();
            level++;
            while(size--){
                auto front=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int new_x=front.first+dir[i];
                    int new_y=front.second+dir[i+1];
                    if(new_x>=0&&new_y>=0&&new_x<m&&new_y<n&&grid[new_x][new_y]==1){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=2;
                        fresh--;
                    }
                }

            }
        }
        if(fresh>0) return -1;
        if(level==-1) return 0;
        else return level;
    }
};