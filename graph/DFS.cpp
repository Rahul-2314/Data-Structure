class Solution {
  private:
    //dfsCore func - handles traversal of one component
    void dfsCore(vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &ans){
        visited[node] = true;
        ans.push_back(node);
        
        // recursively visit all adjacent nodes
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfsCore(adj, visited, neighbour, ans);
            }
        }
    }
    
    
  public:
    // BFS of a Connected/Disconnected Graph components
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size(); //no. of nodes
        vector<int> ans;    //store answer - bfs traversal
        
        vector<bool> visited(n, false);    //track visited node
        
        // traverse all vertex/components of graph
        for(int i=0; i<n; i++){     //all components
            if(!visited[i]){
                dfsCore(adj, visited, i, ans);
            }
        }
        
        return ans;
    }
};
