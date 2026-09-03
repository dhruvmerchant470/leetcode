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
        vector<vector<int>>edges;
        int n=points.size();
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                vector<int>edges1;
                edges1.push_back(abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]));
                edges1.push_back(i);
                edges1.push_back(j);
                edges.push_back(edges1);
            }
        }
        sort(edges.begin(),edges.end());
        vector<int>parent(n);
        vector<int>rank(n,0);
        int sum=0;
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<edges.size();i++){
            int u=findparent(parent,edges[i][1]);
            int v=findparent(parent,edges[i][2]);
            int w=edges[i][0];
            if(u!=v){
                uniond(parent,rank,u,v);
                sum+=w;
            }
        }
        return sum;
    }
};