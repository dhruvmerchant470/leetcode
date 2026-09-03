class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, int parent,vector<vector<int>>& res){
        visited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                res[it].push_back(parent);
                dfs(adj,visited,it,parent,res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++){
            vector<int>visited(n);
            dfs(adj,visited,i,i,res);
        }
        for(int i=0;i<res.size();i++) sort(res[i].begin(),res[i].end());
        return res;
    }
};