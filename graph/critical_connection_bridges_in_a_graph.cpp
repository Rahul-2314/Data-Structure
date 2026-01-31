class Solution {

private:
    void dfs(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<vector<int>>& adj, vector<vector<int>>& ans) {

        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (auto nbr : adj[node]) {
            if (nbr == parent) {
                continue;
            }

            if (!visited[nbr]) {
                dfs(nbr, node, timer, disc, low, visited, adj, ans); // nbr becomes node and node becomes parent
                low[node] = min(low[node], low[nbr]);

                // check for bridge/critical connection
                if (low[nbr] > disc[node]) {
                    ans.push_back({node, nbr});
                }
            } else {
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Tarjan’s Algorithm for Bridges (Critical Connections) :

        // create adjacency list
        int e = connections.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < e; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        int parent = -1;
        vector<bool> visited(n, false);

        vector<vector<int>> ans;

        // dfs
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, parent, timer, disc, low, visited, adj, ans);
            }
        }

        return ans;
    }
};
