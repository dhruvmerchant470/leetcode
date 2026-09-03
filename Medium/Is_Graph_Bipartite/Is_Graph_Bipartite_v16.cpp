class Solution {
public:
    bool dfs(vector<vector<int>>&adj,int node,vector<int>&color,vector<int>&visited){
        visited[node]=true;
        for(auto nbr: adj[node]){
            if(!visited[nbr]){
                color[nbr]=!color[node];
                if(dfs(adj,nbr,color,visited)) return true;
            } else if(color[nbr]==color[node]) return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>visited(V,0);
        vector<int>color(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(graph,i,color,visited)) return false;
            }
        }
        return true;
    }
};