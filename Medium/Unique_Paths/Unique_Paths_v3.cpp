class Solution {
public:
    int uniquePaths(int m, int n) {
        long int res = 1;
        for(int i=1;i<=n-1;i++){
            res = res * (m+i-1)/i;
        }
        return res;
    }
};