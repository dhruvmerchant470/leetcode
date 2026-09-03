class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<bool>&visited, vector<bool>&color, int node){
        visited[node] = true;
        for(auto nbr: graph[node]){
            if(!visited[nbr]){
                color[nbr] = !color[node];
                if(dfs(graph,visited,color,nbr)) return true;
            }else if(color[nbr]==color[node]) return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<bool>color(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(graph,visited,color,i)) return false;
            }
        }
        return true;
    }
};