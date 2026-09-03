class Solution {
public:
    bool isPossible(vector<string>&board,int row,int col){
        if(board[row][col]=='Q') return false;
        for(int i=row;i>=0;i--) if(board[i][col]=='Q') return false;
        int r = row,c = col;
        while(r>=0&&c>=0){
            if(board[r--][c--]=='Q') return false;
        }
        r = row;
        c= col;
        while(r>=0 && c<board.size()) {
            if(board[r--][c++]=='Q') return false;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,int index,vector<string>&board){
        if(index==board.size()){
            ans.push_back(board);
            return;
        }

        //iterationg all cols;
        for(int i=0;i<board.size();i++){ 

            //index-->row i-->col
            if(isPossible(board,index,i)){
                board[index][i]='Q';
                solve(ans,index+1,board);
                board[index][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      vector<string>board(n);
      string s(n,'.');
      for(int i=0;i<n;i++) board[i]=s;  
      solve(ans,0,board);
      return ans;
    }
};