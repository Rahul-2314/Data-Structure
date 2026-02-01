//Position this line where user code will be pasted.
class Solution {
  private:
    void topoSortCore(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj){
        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                topoSortCore(neighbour, visited, st, adj);
            }
        }
        
        st.push(node);
    }
    
    void kosarajuDfs(int node, vector<bool> &visited, vector<vector<int>> &transpose){
        visited[node] = true;
        
        for(auto nbr : transpose[node]){
            if(!visited[nbr]){
                // count++;
                kosarajuDfs(nbr, visited, transpose);
            }
        }
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
        
        // step 1 - perform Topological sort
        vector<bool>visited(v, false);
        stack<int> st;  //needed in this algo for getting nodes order
        
        for(int i=0; i<v; i++){
            if(!visited[i]){
                topoSortCore(i, visited, st, adj);
            }
        }
        
        // step 2 - create a transpose graph (as stack give top-down order after topo sort)
        vector<vector<int>> transpose(v);
        
        for(int i=0; i<v; i++){
            visited[i] = false; //re-assign visited false for further use in algo
            for(auto nbr : adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        
        // step 3 - dfs call using transpose and above ordering
        int count = 0;  //number of strongly connected components in the graph
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!visited[top]){
                count++;
                kosarajuDfs(top, visited, transpose);
            }
        }
        
        return count;
    }
};
