class Solution {
  private:
    //bfsCore func - handles traversal of one component
    
    void bfsCore(vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &ans){
        queue<int> q;   //helper for bfs (traverse one after another)
                
        visited[node] = true;   //mark visited true for the node
        q.push(node);  //push node into queue
        
        while(!q.empty()){
            int frontNode = q.front();  //take front node and remove it from queue
            q.pop();
            
            ans.push_back(frontNode);   //store frontnode (auto i : adj[frontNode]){o ans
            
            // traverse all neighbours of front node (which are not visited yet)
            for(auto neighbour : adj[frontNode]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;  //mark visited true
                    q.push(neighbour);
                }
            }
        }
    }
    
  public:
    // BFS of a Connected/Disconnected Graph components
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size(); //no. of nodes
        vector<int> ans;    //store answer - bfs traversal
        
        vector<bool> visited(n, false);    //track visited node
        
        // traverse all vertex/components of graph
        for(int i=0; i<n; i++){     //all components
            if(!visited[i]){
                bfsCore(adj, visited, i, ans);
            }
        }
        
        return ans;
    }
};
