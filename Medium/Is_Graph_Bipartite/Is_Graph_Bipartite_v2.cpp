class Solution {
public:
    void dfs(vector<int>& visited, vector<vector<int>>& adj, int node) {
        visited[node] = true;
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(visited, adj, neighbour);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        queue<int> q;
        int V = adj.size();
        vector<bool> color(V, false);
        
        vector<int> visited(V, 0);
        vector<int> visited1(V, 0);
        bool flag = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                q.push(i);
                color[i] = true;
                while (!q.empty()) {
                    int front = q.front();
                    q.pop();
                    for (auto neighbour : adj[front]) {
                        if (!visited[neighbour]) {
                            visited[neighbour] = 1;
                            q.push(neighbour);
                            color[neighbour] = !color[front];
                        }
                        else if(visited[i]&&color[neighbour]==color[front]) return false;
                    }
                }
            }
        }
        // for (int i = 0; i < color.size(); i++)
        //     cout << color[i] << " ";
        // cout << endl;
        // for (int i = 0; i < V; i++) {
        //     int co = color[i];
        //     for (auto neighbour : adj[i]) {
        //         if (color[neighbour] == co)
        //             return false;
        //     }
        // }

        return true;
    }
};