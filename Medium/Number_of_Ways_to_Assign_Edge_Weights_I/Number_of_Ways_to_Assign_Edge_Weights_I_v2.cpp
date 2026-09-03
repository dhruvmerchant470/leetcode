class Solution {
public:
    #define MOD 1000000007
    int expon(int a,int b){
        if(b==0) return 1;
        if(b==1) return a;
        int t = expon(a,b/2)%MOD;
        t = (1LL*(t%MOD)*(t%MOD))%MOD;
        if(b&1) t = ((t%MOD) * (a%MOD))%MOD;
        return t;
    }
    int max_depth = -1;
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&visited,int node, int depth){
        max_depth = max(max_depth,depth);
        visited[node]=1;
        for(auto nbr: adj[node]){
            if(!visited[nbr]){
                dfs(adj,visited,nbr,depth+1);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = adj.size();
        vector<int>visited(n+1,0);
        dfs(adj,visited,1,0);
        cout<<max_depth<<endl;
        
        return expon(2,max_depth-1);
    }
};