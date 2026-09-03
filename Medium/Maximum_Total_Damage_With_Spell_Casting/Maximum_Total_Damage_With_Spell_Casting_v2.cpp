class Solution {
public:
    #define ll long long
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>mp;
        for(auto p: power){
            mp[p]+=p;
        }
        vector<ll>new_vec;
        for(auto it: mp){
            new_vec.push_back(it.first);
        }
        ll n = new_vec.size();
        vector<ll>dp(n+1,0);
        for(ll i=1;i<=n;i++){
            ll take = mp[new_vec[i-1]];
            ll skip = dp[i-1];
            ll j = i-1;
            while(j>=1 && new_vec[j-1]>=new_vec[i-1]-2){
                j--;
            }
            if(j>=0) take += dp[j];
            dp[i] = max(skip,take); 
        }
        
        return dp[n];
    }
};