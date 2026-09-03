class Solution {
public:
    bool isCyclicUtil(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
{
    // If the node is already in the recursion stack, a cycle is detected
    if (recStack[u])
        return true;

    // If the node is already visited and not in recursion stack, no need to check again
    if (visited[u])
        return false;

    // Mark the current node as visited and add it to the recursion stack
    visited[u] = true;
    recStack[u] = true;

    // Recur for all neighbors
    for (int x : adj[u])
    {
        if (isCyclicUtil(adj, x, visited, recStack))
            return true;
    }

    // Remove the node from the recursion stack
    recStack[u] = false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        unordered_map<int,vector<int>>adj;
        vector<bool>visited(numCourses,0);
        vector<bool>recStack(numCourses,0);
        for(auto i:prereq){
            if(i[0]==i[1]) return false;
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool ans=isCyclicUtil(adj,i,visited,recStack);
                if(ans) return false;
            }
        }
        return true;
    }
};