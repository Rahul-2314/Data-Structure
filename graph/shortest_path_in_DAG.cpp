// User function Template for C++
class Solution {
  private:
    //get adjacency list - directed fraph
    void getAdjacency(int n, int m, vector<vector<int>> &edges, vector<vector<pair<int,int>>> &adj){
        // n = no. of nodes
        // m = no. of edges
        // edges[i] = {u, v, w}
    
        // add edges
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
    
            adj[u].push_back({v, w});   //store node with weight
        }
    }
    
    // topoSortCore func - dfs traversal and store node into stack from last/end while backtracking
    void topoSortCore(int node, vector<bool> &visited, stack<int> &st, vector<vector<pair<int, int>>> &adj){
        visited[node] = true;
        
        // recursively visit all adjacent nodes
        for(const auto& [neighbour, weight] : adj[node]){
            if(!visited[neighbour]){
                topoSortCore(neighbour, visited, st, adj);
            }
        }
        
        st.push(node);  //push node into stack while backtracking (IMP***)
    }
    
    // Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u→v, vertex u comes before v in the ordering. There may be several topological orderings for a graph.
    // but in this problem we dont require array only need topo stack - track dfs order
    void topoSortUtil(int V, vector<vector<pair<int, int>>> &adj, stack<int> &topoSt) {
        // code here
        vector<bool>visited(V, false);  //track visited
        
        // call dfs for all components
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topoSortCore(i, visited, topoSt, adj);
            }
        }
    }
    
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // step 1: build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        getAdjacency(V, E, edges, adj);
        
        // step 2: perform topo sort
        stack<int> topoSt;  //track dfs order - we only need this stack to solve this proble, topo array not required
        topoSortUtil(V, adj, topoSt);
        
        // step 3: calculate shortest path in DAG using topo-Stack and adjacency list
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;    //because, here source = 0
        
        while(!topoSt.empty()){
            int top = topoSt.top();
            topoSt.pop();
            
            // INT_MAX + w overflows and becomes a negative number -> This may incorrectly update dist[v]
            // so handle this early - unreachable node handling
            if(dist[top] == INT_MAX) continue;  //unreachable node
            
            for(auto i : adj[top]){
                int v = i.first;
                int w = i.second;
                
                if(dist[top]+w < dist[v]){ //update dist if less found
                    dist[v] = dist[top] + w;
                }
            }
        }
        
        // replace INT_MAX with -1 : problem requirement
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
