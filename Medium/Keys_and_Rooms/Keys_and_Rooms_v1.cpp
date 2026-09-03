class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it: rooms[curr]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++) if(!visited[i]) return false;
        return true;
    }
};