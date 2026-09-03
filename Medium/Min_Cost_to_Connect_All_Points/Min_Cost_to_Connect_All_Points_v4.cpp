class Solution {
public:
    int findparent(vector<int>&parent,int node){
        if(node==parent[node]) return node;
        else return parent[node]=findparent(parent,parent[node]);
    }
    void uniond(vector<int>&parent,vector<int>&rank,int u,int v){
        u=findparent(parent,u);
        v=findparent(parent,v);
        if(rank[u]<rank[v]) parent[u]=v;
        else if(rank[u]>rank[v]) parent[v]=u;
        else {
            parent[u]=v;
            rank[v]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>>edges;
        int n=points.size();
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                edges.emplace_back(abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]),i,j);
            }
        }
        sort(edges.begin(),edges.end());
        vector<int>parent(n);
        vector<int>rank(n,0);
        int sum=0;
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto [len,u,v]: edges){
            u=findparent(parent,u);
            v=findparent(parent,v);
            int w=len;
            if(u!=v){
                uniond(parent,rank,u,v);
                sum+=w;
            }
        }
        return sum;
    }
};