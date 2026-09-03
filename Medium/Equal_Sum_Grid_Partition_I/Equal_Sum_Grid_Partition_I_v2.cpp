class Solution {
public: 
    #define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n = grid[0].size();
        ll m = grid.size();
        ll sum =0;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++) sum+=grid[i][j];
        }
        if(sum&1) return false;
        sum/=2;
        ll s =0;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++) s+=grid[i][j];
            if(s==sum) return true;
        }
        s=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++) s+=grid[j][i];
            if(s==sum) return true;
        }
        return false;
    }
};