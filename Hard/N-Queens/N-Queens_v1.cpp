class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n){
        if(board[row][col]=='Q') return false;
        for(int i=row;i>=0;i--) if(board[i][col]=='Q') return false;
        int r=row,c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row;c=col;
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;
    }
    void solve(vector<string>&board,vector<vector<string>>&ans,int index,int n){
        if(index==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,index,i,n)){
                board[index][i]='Q';
                solve(board,ans,index+1,n);
                board[index][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>>ans;
       vector<string>board(n);
       string s(n,'.');
       for(int i=0;i<n;i++) board[i]=s;
    //    cout<<"hi"<<endl;
       solve(board,ans,0,n);
       return ans; 
    }
};