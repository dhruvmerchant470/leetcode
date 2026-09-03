class Solution {
public:
    int ans = -1;

    void dfs(vector<int>& edges, int node,
             vector<int>& state,
             vector<int>& depth,
             int currDepth) {

        state[node] = 1;
        depth[node] = currDepth;

        int nbr = edges[node];

        if (nbr != -1) {
            if (state[nbr] == 0) {
                dfs(edges, nbr, state, depth, currDepth + 1);
            }
            else if (state[nbr] == 1) {
                // nbr is currently in this DFS path
                int len = depth[node] - depth[nbr] + 1;
                ans = max(ans, len);
            }
        }

        state[node] = 2;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> state(n, 0);
        vector<int> depth(n, 0);

        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(edges, i, state, depth, 0);
            }
        }

        return ans;
    }
};