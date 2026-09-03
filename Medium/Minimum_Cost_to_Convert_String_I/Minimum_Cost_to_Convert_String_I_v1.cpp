class Solution {
public:
    #define ll long long
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>dist(26,vector<ll>(26,LLONG_MAX));
        for(ll i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(1LL*cost[i],dist[original[i]-'a'][changed[i]-'a']);
        }
        for(ll i=0;i<26;i++) dist[i][i]=0;
        for(ll k=0;k<26;k++){
            for(ll i=0;i<26;i++){
                for(ll j=0;j<26;j++){
                    if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        ll n = source.size();
        ll c = 0;
        for(ll i=0;i<n;i++){
            ll s = source[i]-'a';
            ll t = target[i]-'a';
            if(dist[s][t]<LLONG_MAX) c+=dist[s][t];
            else return -1;
        }
        return c;
    }
};