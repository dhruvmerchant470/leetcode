class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<routes.size();i++){
            for(auto it: routes[i]){
                adj[it].push_back(i);
            }
        }
        queue<int>q;
        unordered_map<int,bool>visited;
        for(auto it: adj[source]){
            visited[it]=1;
            q.push(it);
        }
        int cnt = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop();
                for(auto it: routes[top]){
                    if(it==target){
                        return cnt;
                    }
                    for(auto it2 : adj[it]){
                        if(!visited[it2]){
                            visited[it2]=1;
                            q.push(it2);
                        }
                    }
                }
            }
            cnt+=1;
        }
        return -1;
    }
};