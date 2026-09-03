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
        vector<ll>dp(n,0);
        for(ll i=0;i<n;i++){
            ll take = mp[new_vec[i]];
            ll skip = i>0?dp[i-1]:0;
            ll j = i-1;
            while(j>=0 && new_vec[j]>=new_vec[i]-2){
                j--;
            }
            if(j>=0) take += dp[j];
            dp[i] = max(skip,take); 
        }
        
        return dp[n-1];
    }
};