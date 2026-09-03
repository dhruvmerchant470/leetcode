class Solution {
public:
    
    // void dfs(vector<int>&disc, vector<int>&low, vector<bool>& visited,vector<vector<int>>&adj, int parent,vector<vector<int>>&result,int node, int &time){
    //     visited[node]=true;
    //     disc[node]=low[node]=time++;
    //     for(auto nbr: adj[node]){
    //         if(nbr==parent) continue;
    //         if(!visited[nbr]) {
    //             dfs(disc,low,visited,adj,node,result,nbr,time);
    //             low[node]=min(low[node],low[nbr]);
    //             if(low[nbr]>disc[node]){
    //                 //only one way to get to this node
    //                 vector<int>ans;
    //                 ans.push_back(node);
    //                 ans.push_back(nbr);
    //                 result.push_back(ans);
    //             }
    //         }
    //         else{
    //             low[node]=min(low[node],disc[nbr]);
    //         }
            
    //     }
    // }
    
    int two_ec(vector<vector<int>>&adj,int node, int parent,vector<bool>&visited, vector<int>&arrival,
    vector<vector<int>>&result,int &time){
        visited[node]=true;
        arrival[node]=time++;
        int deepest=arrival[node];
        for(auto nbr: adj[node]){
            int min1;
            if(!visited[nbr]){
                min1=two_ec(adj,nbr,node,visited,arrival,result,time);
            }
            else if(nbr!=parent){
                min1=arrival[nbr];
            }
            deepest=min(deepest,min1);
        }
        if(parent!=-1 && arrival[node]==deepest) {
            result.push_back({parent,node});
        }
        return deepest;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // vector<int>disc(n,-1);
        // vector<int>low(n,-1);
        // vector<bool>visited(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int time=0;
        vector<bool>visited(n,false);
        vector<int>arrival(n,-1);
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                two_ec(adj,i,-1,visited,arrival,result,time);
            }
        }
        return result;
    }
};