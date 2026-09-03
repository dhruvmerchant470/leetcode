class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       //connnections represents number of edges
       int e=connections.size();
       if(e<n-1) return -1; 
       
       vector<int>parent(n);
       for(int i=0;i<n;i++) parent[i]=i;
       
       int cnt=n; //total disjoint components at the start.
       for(int i=0;i<e;i++){
            int u=connections[i][0],v=connections[i][1];
            int pu=findparent(parent,u);
            int pv=findparent(parent,v);
            if(pu!=pv){
                parent[pu]=pv;
                cnt--; //2 disconnected components are now connected so total disconnexted components reduced by 1.
            }
       }
       return cnt-1; //now total disconnected compoents =cnt and to connect thm we need cnt-1 edges;

    }

    int findparent(vector<int>&parent,int u){
        if(parent[u]!=u){
            return findparent(parent,parent[u]);
        }
        return parent[u];
    }
};