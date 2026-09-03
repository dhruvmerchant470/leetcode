class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color,
             vector<int>& visited, int node) {
        visited[node] = 1;
        for (auto nbr : graph[node]) {
            if (!visited[nbr]) {
                color[nbr] = !color[node];
                if (!dfs(graph, color, visited, nbr))
                    return false;
            } else if (visited[nbr] && color[nbr] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> color(V, 0);
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if(!visited[i]){
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                visited[top]=1;
                for (auto nbr : graph[top]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        color[nbr] = !color[top];
                    } else if (color[nbr] == color[top])
                        return false;
                }
            }
            }
        }

        return true;
    }
};