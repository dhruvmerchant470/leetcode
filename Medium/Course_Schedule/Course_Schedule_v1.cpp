class Solution {
public:
//question of cycle detection in DAG

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto i:prerequisites){
                adj[i[0]].push_back(i[1]);
                if(i[0]==i[1]) return false;
            }
        for(int i=0;i<numCourses;i++){
            
            for(auto j:adj[i]) {
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            cnt++;
            
            q.pop();
            for(auto i: adj[front]){
                if(!visited[i]){
                    indegree[i]--;
                    if(indegree[i]==0) q.push(i);
                }
            }
        }
        if(cnt==numCourses) return true; //no cycle
        else return false;
        }
    
};