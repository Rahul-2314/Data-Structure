#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>   //generic -> all d-type accepted

class Graph {
    public:
        unordered_map<T, list<T>> adj;  //adj list

        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed graph

            // create an edge from u to v
            adj[u].push_back(v);

            if(!direction){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            cout<< endl << "Adjacency List :" <<endl;

            for(auto i : adj){
                cout<< i.first << " -> ";
                for(auto j : i.second){
                    cout<< j << ", ";
                }
                cout<<endl;
            }
        }
};


int main(){

    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter number of edges : ";
    cin>>m;

    Graph<int> g;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, false);
    }

    // printing graph
    g.printAdjList();

    return 0;
}