class Solution {
public:
    void dfs(vector<int>&disc, vector<int>&low, vector<bool>& visited,unordered_map<int,list<int>>&adj, int parent,vector<vector<int>>&result,int node, int &time){
        visited[node]=true;
        disc[node]=low[node]=time++;
        for(auto nbr: adj[node]){
            if(nbr==parent) continue;
            if(!visited[nbr]) {
                dfs(disc,low,visited,adj,node,result,nbr,time);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>disc[node]){
                    //only one way to get to this node
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
            
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<bool>visited(n,false);
        unordered_map<int,list<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>result;
        int time=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(disc,low,visited,adj,-1,result,i,time);
            }
        }
        return result;
    }
};