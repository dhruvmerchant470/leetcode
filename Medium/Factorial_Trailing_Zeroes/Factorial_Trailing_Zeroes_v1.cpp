class Solution {
public:
    int solve(int n){
        int cnt=0;
        long long five=5;
        while(n/five>0){
            cnt+=n/five;
            five*=5;
        }
        return cnt;
    }
    int trailingZeroes(int n) {
        return solve(n);
    }
};