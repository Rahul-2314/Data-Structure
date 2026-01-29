class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // create adjacency list (1-based indexing)
        vector<vector<pair<int,int>>> adj(V);
    
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
    
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // apply prims algo ===========================
        vector<int>key(V, INT_MAX);    //0-based indexing
        vector<bool>mst(V, false);
        vector<int>parent(V, -1);
        int res = 0;

        // Min-heap: {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Handle disconnected graph
        for (int start = 0; start < V; start++) {
            if (!mst[start]) {
                key[start] = 0;
                pq.push({0, start});
    
                while (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    
                    int wt = top.first;
                    int u = top.second;
    
                    if (mst[u]) continue;
                    
                    res += wt;
                    mst[u] = true;
    
                    for (auto &nbr : adj[u]) {
                        int v = nbr.first;
                        int w = nbr.second;
    
                        if (!mst[v] && w < key[v]) {
                            key[v] = w;
                            parent[v] = u;
                            pq.push({key[v], v});
                        }
                    }
                }
            }
        }
    
        return res;
    }
};
