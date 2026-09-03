class cmp{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        pq.push({k,0});
        dist[k]=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            for(auto nbr:adj[top.first]){
                if(nbr.second+top.second<dist[nbr.first]){
                    dist[nbr.first]=nbr.second+top.second;
                    pq.push({nbr.first,dist[nbr.first]});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e8) return -1;
            else ans=max(ans,dist[i]);
        }
        
        return ans;
    }
};