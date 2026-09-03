class Solution {
public:
    static constexpr int MOD = 1000000007;

    int expon(long long a, int b) {
        if (b == 0) return 1;
        if (b == 1) return a % MOD;

        long long t = expon(a, b / 2);
        t = (t * t) % MOD;

        if (b & 1)
            t = (t * (a % MOD)) % MOD;

        return (int)t;
    }

    int max_depth = -1;

    void dfs(vector<vector<int>>& adj, vector<int>& visited,
             int node, int depth) {
        max_depth = max(max_depth, depth);
        visited[node] = 1;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(adj, visited, nbr, depth + 1);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n + 1, 0);
        dfs(adj, visited, 1, 0);

        return expon(2, max_depth - 1);
    }
};