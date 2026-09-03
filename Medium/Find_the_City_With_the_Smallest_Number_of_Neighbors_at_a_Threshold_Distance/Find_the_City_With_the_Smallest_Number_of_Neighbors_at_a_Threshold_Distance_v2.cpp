class Solution {
public:
    #define pii pair<int,int>
    int solve(vector<vector<pair<int,int>>>&adj, int k, int node,int n){
        vector<int>dist(n,INT_MAX);
        dist[node]=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({dist[node],node});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            for(auto nbr: adj[top.second]){
                if(nbr.second+dist[top.second]<dist[nbr.first]){
                    dist[nbr.first] = nbr.second + dist[top.second];
                    pq.push({dist[nbr.first],nbr.first});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dist[i]<=k) cnt+=1;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pii>>adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        int index = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int t = solve(adj,distanceThreshold,i,n);
            if(mini>=t){
                mini = t;
                index = i; 
            }
        }
        return index;
    }
};