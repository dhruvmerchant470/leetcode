class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> color(V, 0);
        queue<int> q;
        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++) {
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                visited[top] = 1;
                for (auto nbr : graph[top]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        color[nbr] = !color[top];
                    } else if (color[nbr] == color[top])
                        return false;
                }
            }
        }
        return true;
    }
};