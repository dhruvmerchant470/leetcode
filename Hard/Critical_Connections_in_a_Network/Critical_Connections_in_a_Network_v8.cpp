class Solution {
public:
    int timer=0;
    void dfs(vector<vector<int>>&adj,vector<vector<int>>&bridges,vector<int>&vis,vector<int>&tim,vector<int>&low,int node,int parent){
        vis[node]=1;
        tim[node]=low[node]=timer++;
        for(auto nbr:adj[node]){
            if(nbr==parent) continue;
            if(vis[nbr]==0){
                dfs(adj,bridges,vis,tim,low,nbr,node);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>tim[node]){
                    bridges.push_back({nbr,node});
                }
            }
            else{
                low[node]=min(low[node],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        vector<int>low(n),tim(n);
        vector<vector<int>>bridges;
        vector<vector<int>>adj(n);
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(adj,bridges,vis,tim,low,i,-1);
        }
        return bridges;
    }
};