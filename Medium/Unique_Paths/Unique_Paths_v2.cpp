#define ll long long
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        double N=(n+m-2);
        double r=min(n-1,m-1);
        double ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(N-r+i)*1.0/i;
        }
        return ans;
    }
};