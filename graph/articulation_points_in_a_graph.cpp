// User function Template for C++

class Solution {
  private:
    // Tarjan’s DFS
    void dfs(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<int> adj[], vector<bool>& isAP) {

        visited[node] = true;
        disc[node] = low[node] = timer++;
        
        int children = 0;

        for (auto nbr : adj[node]) {
            if (nbr == parent) {
                continue;
            }

            if (!visited[nbr]) {
                children++;
                dfs(nbr, node, timer, disc, low, visited, adj, isAP); // nbr becomes node and node becomes parent
                low[node] = min(low[node], low[nbr]);

                // non-root articulation point
                if (low[nbr] >= disc[node] && parent != -1) {
                    isAP[node] = true;
                }
                
            } else {
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
        
        // root articulation point
        if(parent == -1 && children > 1){
            isAP[node] = true;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        
        // Articulation Point (Cut Vertex) using Tarjan’s DFS
        
        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        int parent = -1;
        vector<bool> visited(V, false);

        vector<bool> isAP(V, false);    //store articulation points

        // dfs
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, parent, timer, disc, low, visited, adj, isAP);
            }
        }
        
        vector<int> ans;
        
        for(int i=0; i<V; i++){
            if(isAP[i]){
                ans.push_back(i);
            }
        }
        
        //output requirement
        if(ans.size() == 0) {
            ans.push_back(-1);
        }
        
        return ans;
    }
};
