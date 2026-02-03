// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int e = edges.size();
        
        vector<int> dist(V, 1e8);   // (1e8 or 10**8) mentioned in problem statement
        dist[src] = 0;
        
        // step 1: relax edges V-1 times
        for(int i=0; i<V-1; i++){
            for(int j=0; j<e; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                // edge relaxation logic
                if(dist[u] != 1e8 && (dist[u] + wt < dist[v])){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // step 2: one more relaxation pass to detect negative cycle
        for(int j=0; j<e; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            // edge relaxation logic
            if(dist[u] != 1e8 && (dist[u] + wt < dist[v])){
                return {-1};    //negative cycle found/exist
            }
        }
        
        return dist;
    }
};
