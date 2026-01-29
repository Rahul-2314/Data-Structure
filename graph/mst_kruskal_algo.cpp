// User function Template for C++
class Solution {
  private:
    // logic of compare for sorting of edges acc to their weights
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2]; //compare weights
    }
    
    //initialization of rank and parent
    void makeSet(vector<int> &parent, vector<int> &rank, int V){
        for(int i=0; i<V; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    // find parent logic : finds the ultimate parent of a node using path compression to flatten the DSU tree for faster future queries
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent, parent[node]);
    }
    
    // following disjoint set concepts
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
        // u = findParent(parent, u);
        // v = findParent(parent, v);
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(), edges.end(), cmp);
        
        vector<int> parent(V);
        vector<int> rank(V);
        makeSet(parent, rank, V);
        
        int minWt = 0;
        
        // if same parent ->ignore
        // else -> union
        for(int i=0; i<edges.size(); i++){
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int wt = edges[i][2];
            
            if(u != v){
                minWt += wt;   //add min weight
                unionSet(u, v, parent, rank);
            }
            // ignore else(u==v) case because, parents same -> both are already included in MST
            // if further include them , it will form a loop.
        }
        
        return minWt;
    }
};
