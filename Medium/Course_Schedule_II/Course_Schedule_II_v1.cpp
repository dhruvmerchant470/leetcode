class Solution {
public:
    unordered_map<int,list<int>>adj;

    bool cycle(int n,vector<int>&visited,vector<int>&ans){
        vector<int>indegree(n,0);
  
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            visited[front]=1;
            ans.push_back(front);
            q.pop();
            cnt++;
            for(auto nbr:adj[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }

        return cnt!=n;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>ans(numCourses);
        stack<int>s;
        vector<int>visited(numCourses);
        if(n==0){
            for(int i=0;i<numCourses;i++) ans[i]=i;
            return ans;
        }
        if(cycle(numCourses,visited,ans)){
            cout<<"1"<<endl;
            return {};
        } 
        else{
            
            vector<int>ans1;
            stack<int>s1;
            vector<int>visited1(numCourses);
            cycle(numCourses,visited,ans1);
            return ans1;

        }
    }
};