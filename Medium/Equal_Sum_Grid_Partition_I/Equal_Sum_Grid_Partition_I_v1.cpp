class Solution {
public: 
    #define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n = grid[0].size();
        ll m = grid.size();
        ll sum =0;
        vector<ll>col_sum(n,0),row_sum(m,0);
        for(ll i=0;i<m;i++){
            ll s = 0;
            for(ll j=0;j<n;j++) s+=grid[i][j];
            row_sum[i]=s;
            sum+=s;
        }
        if(sum&1) return false;
        for(ll i=0;i<n;i++){
            ll s = 0;
            for(ll j=0;j<m;j++) s+=grid[j][i];
            col_sum[i]=s;
        }
        sum/=2;
        ll tmp = 0;
        for(ll i=0;i<n;i++){
            tmp+=col_sum[i];
            if(tmp==sum) return true;
        }
        tmp=0;
        for(ll i=0;i<m;i++){
            tmp+=row_sum[i];
            if(tmp==sum) return true;
        }
        return false;
    }
};