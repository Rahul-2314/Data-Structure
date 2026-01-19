class Solution {
  private:
    //get adjacency list - directed fraph
    void getAdjacency(int n, int m, vector<vector<int>> &edges, vector<vector<int>> &adj){
        // n = no. of nodes
        // m = no. of edges
    
        // add edges
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
    
            adj[u].push_back(v);
        }
    }
    
    // topoSortCore func - dfs traversal and store node into stack from last/end while backtracking
    void topoSortCore(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj){
        visited[node] = true;
        
        // recursively visit all adjacent nodes
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                topoSortCore(neighbour, visited, st, adj);
            }
        }
        
        st.push(node);  //push node into stack while backtracking (IMP***)
    }
    
  public:
    // Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u→v, vertex u comes before v in the ordering. There may be several topological orderings for a graph.
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int E = edges.size();
        
        // create adjacency list
        vector<vector<int>> adj(V);
        getAdjacency(V, E, edges, adj); //creating adjacency list
        
        vector<bool>visited(V, false);  //track visited
        stack<int> st;  //dfs order track
        
        // call dfs for all components
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topoSortCore(i, visited, st, adj);
            }
        }
        
        // built ans
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
