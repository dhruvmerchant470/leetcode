class Solution {
public:
    bool ans(vector<bool>&color,int node,vector<bool>&visited,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto nbr: adj[top]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    color[nbr]=!color[top];
                    q.push(nbr);
                }
                else if(color[nbr]==color[top]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);

        }
        vector<bool>color(n,false);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool ans1=ans(color,i,visited,adj);
                if(!ans1) return ans1;
            }
        }
        return true;
    }
};