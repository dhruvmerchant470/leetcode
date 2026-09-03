class Solution {
private:
    unordered_map<string, unordered_map<string, double>> adj;

public:
    bool dfs(string src, string target, double& num,
             unordered_map<string, bool>& visited) {
        visited[src] = 1;
        for (auto nbr : adj[src]) {
            if (nbr.first == target) {
                num = nbr.second;
                return true;
            } else if (visited[nbr.first] == 0)
                if (dfs(nbr.first, target, num, visited)) {
                    num *= 1.0 * nbr.second;
                    return true;
                }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int E = equations.size();
        for (int i = 0; i < E; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];
            adj[u][v] = wt;
            adj[v][u] = 1.0 / wt;
        }
        for (auto& [u, nbrs] : adj) {
            for (auto& [v, weight] : nbrs) {
                cout << u << " -> " << v << " = " << weight << endl;
            }
        }

        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            if (adj.find(queries[i][0]) == adj.end() ||
                adj.find(queries[i][1]) == adj.end()) {
                res.push_back(-1.0);

            } else if (queries[i][0] == queries[i][1]) {
                res.push_back(1.0);
            } else {
                unordered_map<string, bool> visited;
                double num = -1.0;
                dfs(queries[i][0], queries[i][1], num, visited);
                res.push_back(num);
            }
        }
        return res;
    }
};