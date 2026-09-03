class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto i:prereq){
            if(i[0]==i[1]) return false;
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;
            for(auto nbr:adj[top]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        return numCourses==cnt;
    }
};