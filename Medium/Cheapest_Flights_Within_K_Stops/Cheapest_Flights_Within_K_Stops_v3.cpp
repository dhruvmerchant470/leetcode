class cmp{
    public:
    bool operator()(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& times, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n,1e8);
        priority_queue<vector<int>,vector<vector<int>>,cmp>pq;
        pq.push({src,0,0});
        dist[src]=0;
        while(!pq.empty()){
            auto top=pq.top();
            int u=top[0],len=top[1],k1=top[2];
            pq.pop();
            for(auto nbr:adj[u]){
                if(nbr.second+len<dist[nbr.first]&&k>=k1){
                    dist[nbr.first]=nbr.second+len;
                    pq.push({nbr.first,dist[nbr.first],k1+1});
                }
            }
        }
        
        if(dist[dst]==1e8) return -1;
        else return dist[dst];
    }
};