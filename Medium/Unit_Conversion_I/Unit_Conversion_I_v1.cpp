class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        ll n = conversions.size()+1;
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto it: conversions){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<bool>visited(n,false);
        queue<ll>q;
        q.push(0);
        visited[0]=true;
        vector<int>dist(n);
        dist[0]=1;
        while(!q.empty()){
            ll t = q.front();
            q.pop();
            visited[t]=true;
            for(auto nbr: adj[t]){
                if(!visited[nbr.first]){
                    dist[nbr.first] = (dist[t]%MOD*nbr.second%MOD)%MOD;
                    visited[nbr.first] = true;
                    q.push(nbr.first);
                }
            }
        }
        return dist;
    }
};