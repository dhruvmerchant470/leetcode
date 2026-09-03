class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        for(auto it: relations){
            adj[it[0]].push_back(it[1]);
        }
        queue<int>q;
        vector<int>indegree(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto it: adj[i]){
                indegree[it]+=1;
            }
        }
        vector<int>finishTime(n+1,0);
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                finishTime[i] = time[i-1];
            }
        }
        int ans = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans = max(ans,finishTime[curr]);
            for(auto nbr: adj[curr]){
                finishTime[nbr] = max(finishTime[nbr],time[nbr-1]+finishTime[curr]);
                indegree[nbr]-=1;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};