class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool dfs(vector<vector<char>>& board, string word, int index,int x,int y){
        if(index >= word.size()){
            return true;
        }
        // cout<<x<<" "<<y<<endl;
        char t = board[x][y];
        board[x][y] = '.';
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<board.size() && ny<board[0].size() && board[nx][ny]==word[index]){
                if(dfs(board,word,index+1,nx,ny)) return true;
            }
        }
        board[x][y] = t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,1,i,j)) return true;
                }
            }
        }
        return false;
    }
};