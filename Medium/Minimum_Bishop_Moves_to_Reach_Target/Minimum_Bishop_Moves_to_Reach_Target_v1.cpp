class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sx = source[0];
        int sy = source[1];
        int tx = target[0];
        int ty = target[1];
        int tmp1 = sx + sy;
        int tmp2 = tx + ty;
        if(tmp1%2==0){
            if(tmp2%2!=0) return -1;
        }else{
            if(tmp2%2==0) return -1;
        }
        int t1 = tx-sx;
        int t2 = ty-sy;
        if(abs(t1)==abs(t2)) return 1;
        else return 2;
    }
};