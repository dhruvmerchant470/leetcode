class Solution {
public:
    int findP(vector<int>&parent, int node){
        if(parent[node]==node) return node;
        else return parent[node]=findP(parent,parent[node]);
    }
    void uni(vector<int>&parent,vector<int>&rank,int u,int v){
        if(rank[u]<rank[v]){
            parent[u] = v;
        }else if(rank[v]<rank[u]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[v] += 1;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>edges;
        int n = isConnected.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // if(i==j) continue;
                if(isConnected[i][j]){
                    edges.push_back({i,j});
                }
            }
        }
        int total = n;
        for(auto edge : edges){
            int x = findP(parent,edge[0]);
            int y = findP(parent,edge[1]);
            if(x!=y){
                uni(parent,rank,x,y);
                total -= 1;
            }
        }
        return total;
    }
};