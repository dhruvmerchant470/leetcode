class Solution {
public:
    bool isPossible(unordered_map<int,vector<pair<int,int>>>&adj,long long k, int mid,int n){
        // cout<<mid<<endl;
        set<pair<long long,int>>pq;
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        pq.insert({dist[0],0});
        long long tot = 0;
        while(!pq.empty()){
            auto top = *(pq.begin());
            pq.erase(pq.begin());
            if(tot+1LL*top.first>k) return false;
            if(top.second==n-1) return true;

            for(auto nbr : adj[top.second]){
                if(nbr.second<mid) continue;
                if(1LL*nbr.second+1LL*top.first<dist[nbr.first]){
                    auto it = pq.find({dist[nbr.first],nbr.first});
                    if(it!=pq.end()) pq.erase(it);
                    dist[nbr.first]=1LL*nbr.second+1LL*top.first;
                    pq.insert({1LL*dist[nbr.first],nbr.first});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int l = 0;
        int h = -1;
        int n = online.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it : edges){
            if(!online[it[0]] || !online[it[1]]) continue;
            adj[it[0]].push_back({it[1],it[2]});
            h = max(h,it[2]);
        }
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            // cout<<l<<" "<<mid<<" "<<h<<endl;
            if(isPossible(adj,k,mid,n)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
};