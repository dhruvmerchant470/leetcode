class Solution {
    map<int,vector<int>>adj;
    int N;
public:
    int bipartite(int root,vector<int>&color,int c,vector<int>&tmp){
        color[root]=c;
        tmp.push_back(root);
        for(auto nbr: adj[root]){
            if(color[nbr]==c) return false;
            if(color[nbr]==-1 && !bipartite(nbr,color,!c,tmp)) return false;
        }
        return true;
    }
    int bfs(vector<int>&comp){
        int max_depth=1;
        for(int i=0;i<comp.size();i++){
            queue<int>q;
            vector<int>depth(N+1,-1);
            q.push(comp[i]);
            depth[comp[i]]=1;
            while(!q.empty()){
                auto top=q.front();
                q.pop();
                for(auto nbr: adj[top]){
                    if(depth[nbr]==-1){
                        depth[nbr]=depth[top]+1;
                        max_depth=max(max_depth,depth[nbr]);
                        q.push(nbr);
                    }
                }
            }
        }
        return max_depth;
        
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n+1,-1);
        vector<vector<int>>comp;
        N=n;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                vector<int>tmp;
                if(!bipartite(i,color,0,tmp)) return -1;
                comp.push_back(tmp);
            }
        }
        int ans=0;
        for(int i=0;i<comp.size();i++){
            ans+=bfs(comp[i]);
        }
        return ans;
    }
};