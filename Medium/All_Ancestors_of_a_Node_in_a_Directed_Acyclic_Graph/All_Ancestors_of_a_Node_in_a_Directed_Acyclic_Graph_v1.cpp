class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            for(int it: adj[i]){
                indegree[it]+=1;
            }
        }
        queue<int>q;
        vector<set<int>>ans(n);
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto nbr: adj[curr]){
                indegree[nbr]-=1;
                for(int t: ans[curr]) ans[nbr].insert(t);
                ans[nbr].insert(curr);
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        // sort(ans.begin(),ans.end());
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++){
            for(auto it: ans[i]){
                res[i].push_back(it);
            }
        }
        return res;
    }
};