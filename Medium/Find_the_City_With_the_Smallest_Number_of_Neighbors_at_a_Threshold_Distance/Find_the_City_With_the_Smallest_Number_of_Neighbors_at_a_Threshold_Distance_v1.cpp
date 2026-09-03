class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>adj;

    vector<int> dijntras(int source,int n){
        set<pair<int,int>>s;
        vector<int>dist(n,INT_MAX);
        dist[source]=0;
        s.insert({dist[source],source});
        while(!s.empty()){
            auto top=*(s.begin());
            s.erase(s.begin());
            for(auto nbr: adj[top.second]){
                if(nbr.second+top.first<dist[nbr.first]){
                    auto f=s.find({dist[nbr.first],nbr.first});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr.first]=nbr.second+top.first;
                    s.insert({dist[nbr.first],nbr.first});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>dist=dijntras(i,n);
            vector<int>d;
            for(int j=0;j<n;j++){
                if(dist[j]>0 && dist[j]<=distanceThreshold){
                    d.push_back(j);
                }
            }
            ans.push_back(d);
        }
        int final_ans=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(mini>=ans[i].size()){
                mini=ans[i].size();
                final_ans=i;
            }
        }
       return final_ans;
    }
};