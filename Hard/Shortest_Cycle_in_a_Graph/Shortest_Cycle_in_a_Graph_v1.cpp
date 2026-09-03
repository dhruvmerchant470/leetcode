class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, -1);
            vector<int> parent(n, -1);

            queue<int> q;

            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {

                    // Not visited yet
                    if (dist[nbr] == -1) {
                        dist[nbr] = dist[node] + 1;
                        parent[nbr] = node;
                        q.push(nbr);
                    }

                    // Visited and not our parent
                    else if (parent[node] != nbr) {
                        int cycleLength =
                            dist[node] + dist[nbr] + 1;

                        ans = min(ans, cycleLength);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};