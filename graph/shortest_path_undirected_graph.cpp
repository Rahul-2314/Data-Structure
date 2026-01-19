class Solution {
  private:
    //find shortest dist of every nodes from source 
    void findShortestPathBFS(int src, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &dist){
        queue<int> q;
        
        visited[src] = true;
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neighbour : adj[front]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    dist[neighbour] = dist[front] + 1;
                    q.push(neighbour);
                }
            }
        }
    }
    
    
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        int E = edges.size();
        
        // 1. create adjacence list
        vector<vector<int>> adj(V);
    
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false); //track visited nodes
        vector<int> dist(V, -1);  //initial dist of all nodes
        
        // find shortest path - using BFS traversal
        findShortestPathBFS(src, visited, adj, dist);
        
        return dist;
    }
};
