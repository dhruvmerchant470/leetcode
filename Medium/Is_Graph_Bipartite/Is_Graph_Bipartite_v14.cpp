class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<bool> visited(nodes, false);
        vector<bool> color(nodes, false);
        queue<int> q;
        for (int i = 0; i < nodes; i++) {
            if(visited[i]) continue;

            q.push(i);
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                visited[t] = true;
                for (auto nbr : graph[t]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        color[nbr] = !color[t];
                    } else if (color[nbr] == color[t])
                        return false;
                }
            }
        }
        return true;
    }
};