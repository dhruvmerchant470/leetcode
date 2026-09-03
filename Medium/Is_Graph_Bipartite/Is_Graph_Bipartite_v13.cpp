class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&color,vector<int>&vis,int node){
        vis[node]=1;
        for(auto nbr: graph[node]){
            if(!vis[nbr]){
                color[nbr]=!color[node];
                if(dfs(graph,color,vis,nbr)) return true;
            }
            else if(vis[nbr] && color[nbr]==color[node]) return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(graph,color,visited,i)) return false;
            }
        }
        return true;
    }
};