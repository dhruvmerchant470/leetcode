class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int dx[8] = {0,0,1,-1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        priority_queue<pii,vector<pii>,greater<pii>>q;
        int len = 0;
        q.push({1,{0,0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        visited[0][0]=true;
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            int x = curr.second.first;
            int y = curr.second.second;
            if(x==n-1 && y==m-1) return curr.first;
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]==0){
                    visited[nx][ny]=true;
                    q.push({curr.first+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};