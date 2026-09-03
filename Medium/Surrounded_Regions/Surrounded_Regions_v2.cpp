class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][m-1]=='O') q.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[n-1][i]=='O') q.push({n-1,i});
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(board[x][y]=='Y') continue;
            board[x][y] = 'Y';
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]=='O'){
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};