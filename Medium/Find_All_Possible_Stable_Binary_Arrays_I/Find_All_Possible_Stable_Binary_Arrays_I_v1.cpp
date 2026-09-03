int dp[205][205][2][405];
class Solution {
public:
    #define MOD 1000000007
    int helper(int zero,int one,int limit,int last_used,int streak){
        if(zero==0 && one==0) return dp[zero][one][last_used][streak] = 1;
        if(last_used!=-1 && dp[zero][one][last_used][streak]!=-1) return dp[zero][one][last_used][streak];
        int cnt = 0;
        if(zero>0){
            if(last_used==1){
                cnt+=helper(zero-1,one,limit,0,1);
            }
            else if(streak<limit){
                cnt+=helper(zero-1,one,limit,0,streak+1);
            }
        }

        if(one>0){
            if(last_used==0){
                cnt+=helper(zero,one-1,limit,1,1);
            }
            else if(streak<limit){
                cnt+=helper(zero,one-1,limit,1,streak+1);
            }
        }

        if(last_used!=-1) return dp[zero][one][last_used][streak] = cnt%MOD;
        else return cnt%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                for(int k=0;k<2;k++){
                    for(int l=0;l<=2*limit+1;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        return helper(zero,one,limit,-1,0);
    }
};