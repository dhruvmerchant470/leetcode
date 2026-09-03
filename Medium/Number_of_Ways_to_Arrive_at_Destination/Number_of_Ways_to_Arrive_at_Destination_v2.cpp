class Solution {
public:
    #define pll pair<long,long>
    #define MOD 1000000007
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto road: roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        vector<ll>dist(n,LLONG_MAX);
        vector<ll>ways(n,0);
        ways[0]=1;
        dist[0]=1;
        set<pll>pq;
        pq.insert({dist[0],0});
        while(!pq.empty()){
            auto [wt,node] = *pq.begin();
            pq.erase(pq.begin());
            for(auto nbr:adj[node]){
                if(dist[node] + nbr.second < dist[nbr.first]){
                    auto it = pq.find({dist[nbr.first],nbr.first});
                    if(it!=pq.end()) pq.erase(it);
                    dist[nbr.first] = dist[node] + nbr.second;
                    pq.insert({dist[nbr.first],nbr.first});
                    ways[nbr.first] = ways[node];
                }
                else if(dist[node] + nbr.second == dist[nbr.first]){
                    ways[nbr.first] = (ways[nbr.first]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};