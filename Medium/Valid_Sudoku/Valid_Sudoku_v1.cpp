class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            unordered_set<char>s;
            for(int i=0;i<board.size();i++){
                if(board[row][i]=='.') continue;
                if(s.find(board[row][i])!=s.end()) return false;
                else s.insert(board[row][i]);
            }
        }
        for(int col=0;col<board.size();col++){
            unordered_set<char>s;
            for(int i=0;i<board.size();i++){
                if(board[i][col]=='.') continue;
                if(s.find(board[i][col])!=s.end()) return false;
                else s.insert(board[i][col]);
            }
        }
        for(int row=0;row<board.size();row+=3){
            for(int col=0;col<board.size();col+=3){
                unordered_set<char>s;
                for(int i=0;i<9;i++){
                    char ch=board[row+i/3][col+i%3];
                    if(ch=='.') continue;
                    if(s.find(ch)!=s.end()) {
                        return false;
                    }
                    else s.insert(ch);
                }
           }
        }
        return true;
    }
};