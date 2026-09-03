class Solution {
public:
    vector<int>topo(vector<vector<int>>&edges,int k){
        map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        //k vertices
        queue<int>q;
        vector<int>ans;
        vector<int>indegree(k+1,0);
        for(int i=1;i<=k;i++){
            for(auto nbr: adj[i]){
                indegree[nbr]++;
            }
        }
        int cnt=0;
        for(int i=1;i<=k;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;
            ans.push_back(top);
            for(auto nbr: adj[top]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        if(cnt<k) return {};
        else return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>toporow=topo(rowConditions,k);
        vector<int>topocol=topo(colConditions,k);
        vector<vector<int>>matrix(k,vector<int>(k,0));
        if(toporow.size()==0 || topocol.size()==0) return {};
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(toporow[i]==topocol[j]) matrix[i][j]=toporow[i];
            }
        }
        return matrix;
    }
};