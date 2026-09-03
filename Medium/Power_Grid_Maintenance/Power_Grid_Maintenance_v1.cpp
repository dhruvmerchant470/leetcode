class Solution {
public:
    void dfs(int node, int id, vector<vector<int>>& adj, vector<int>& compId, vector<int>& visited, vector<int>& componentNodes) {
        visited[node] = 1;
        compId[node] = id;
        componentNodes.push_back(node);
        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(nbr, id, adj, compId, visited, componentNodes);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<int> compId(c + 1, -1);
        vector<int> visited(c + 1, 0);
        unordered_map<int, set<int>> componentActiveNodes;
        int currId = 0;

        // Build connected components and assign component ID to each node
        for (int i = 1; i <= c; ++i) {
            if (!visited[i]) {
                vector<int> componentNodes;
                dfs(i, currId, adj, compId, visited, componentNodes);
                for (int node : componentNodes) {
                    componentActiveNodes[currId].insert(node);  // all nodes active at start
                }
                currId++;
            }
        }

        vector<int> ans;
        vector<bool> active(c + 1, true);

        for (auto& q : queries) {
            int type = q[0], x = q[1];

            if (type == 2) {
                if (active[x]) {
                    active[x] = false;
                    int cid = compId[x];
                    componentActiveNodes[cid].erase(x);  // remove from active set
                }
            } else {
                if (active[x]) {
                    ans.push_back(x);
                } else {
                    int cid = compId[x];
                    if (componentActiveNodes[cid].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*componentActiveNodes[cid].begin());  // min active node
                    }
                }
            }
        }

        return ans;
    }
};
