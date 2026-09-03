class Solution {
private:
    int dir[5]={-1,0,1,0,-1};
public:
    void dfs(vector<vector<char>>&board,int x,int y){
        board[x][y]='-';
        for(int i=0;i<4;i++){
            int new_x=x+dir[i];
            int new_y=y+dir[i+1];
            if(new_x>=0 && new_y>=0 && new_x<board.size() && new_y<board[0].size() && board[new_x][new_y]=='O'){
                dfs(board,new_x,new_y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++) {
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1);
        }
        for(int i=1;i<board[0].size()-1;i++) {
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[board.size()-1][i]=='O') dfs(board,board.size()-1,i);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='-') board[i][j]='O';
            }
        }   
    }
};