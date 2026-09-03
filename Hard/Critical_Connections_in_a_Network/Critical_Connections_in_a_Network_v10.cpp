class Solution {
public:
    int timer = 0;
    vector<vector<int>>bridges;
    void dfs(vector<int>&low,vector<int>&disc,vector<int>&visited,vector<vector<int>>&adj,int node,int parent){
        low[node]=disc[node]=timer;
        timer+=1;
        visited[node]=true;
        for(auto nbr: adj[node]){
            if(nbr==parent) continue;
            if(!visited[nbr]){
                dfs(low,disc,visited,adj,nbr,node);
                if(low[nbr]<low[node]) low[node]=low[nbr];

                if(low[nbr]>disc[node]) bridges.push_back({nbr,node});
            }else{
                low[node] = min(low[node],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>visited(n,false);
        vector<int>low(n,0);
        vector<int>disc(n,0);
        vector<vector<int>>adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(low,disc,visited,adj,0,-1);
        return bridges;
    }
};