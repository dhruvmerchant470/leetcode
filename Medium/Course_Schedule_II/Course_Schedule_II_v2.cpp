class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }    
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i+=1){
            for(auto it: adj[i]){
                indegree[it]+=1;
            }
        }
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        int cnt=0;
        vector<int>ans;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr);
            cnt+=1;
            for(auto nbr: adj[curr]){
                indegree[nbr]-=1;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(cnt!=n) return {};
        else return ans;
    }
};