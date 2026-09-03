class cmp{
    public:
    bool operator()(pair<double,int>&a,pair<double,int>&b){
        return a.second>b.second;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1,start_node});
        vector<double>prob(n,0);
        prob[start_node]=1;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            for(auto nbr: adj[top.second]){
                if(top.first*nbr.second>prob[nbr.first]){
                    prob[nbr.first]=top.first*nbr.second;
                    pq.push({prob[nbr.first],nbr.first});
                }
            }
        }
        
        return prob[end_node];

    }
};