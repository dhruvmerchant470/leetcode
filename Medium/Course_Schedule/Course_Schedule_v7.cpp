class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
            if(it[0]==it[1]) return false;
        }

        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto nbr: adj[i]){
                indegree[nbr]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<bool>visited(numCourses,false);
        int cnt=0;
        while(!q.empty()){
            int top = q.front();
            cnt+=1;
            q.pop();
            visited[top]=true;
            for(auto nbr: adj[top]){
                if(!visited[nbr]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0) q.push(nbr);
                }
            }
        }

        return cnt==numCourses;
    }
};