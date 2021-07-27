/*
    Bellman-Ford ALgorithm is used to calculate the shortest path of all the vertices in a
    directed graph (also called as digraph) from a certain source vertex.
    It is based on the concept of dynammic programming.
    Unlike Kruskal's algorithm to find the minimum shortest path, 
    Bellman-Ford is applicable when there is a negative weighted edge in the graph.
    But it still does not hold good, if there is a negative weight cycle in a graph.
    The algorithm works fine for undirected graph if there is no negative edge.
*/

// Implementation
#include<bits/stdc++.h>
using namespace std;

// Strcuture to store all the elements of edge in single entity.
class Edge{
    public:
        int source;
        int destination;
        int weight;
};

// Structure of graph with related methods.
class Graph{
    int vertices, numEdges;
    Edge *edges;

    public:
        Graph(int vertices, int edges) {
            this->vertices = vertices;
            this->numEdges = edges;
            this->edges = new Edge[edges];
        }

        void addEdge();
        void Bellman_Ford();
        void printBF(int[]);
};

int main(){
    
    int vertices, edges;

    cout<<"Enter number of vertices and edges of the graph : ";
    cin>>vertices>>edges;

    // Object of graph with 5 vertices.
    Graph graph(vertices, edges);

    // Adding edges to the graph.
    graph.addEdge();

    graph.Bellman_Ford();
    
    return 0;
}

// Method to add an edge in a graph
void Graph::addEdge()
{
    for(int i=0; i<numEdges; i++)
    {
        cout << "Enter source, destination and weight of edge : ";
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }
}

// Method to implement Bellman Ford algorithm.
void Graph::Bellman_Ford()
{
    // Stores shortest path structure
    int parent[vertices];

    // Cost of the node to parent edge weight
    int parent_cost[vertices];

    // Keeps shortest path value of each vertex from source
    vector<int> distance(vertices, INT_MAX);

    // Choosing start point as 0th vertex
    // Start node has no parent
    parent[0] = -1;

    // The shortest path of source to source will be zero.
    distance[0] = 0;

    // updated variable keeps track of iterations so that
    // the loop breaks if no further relaxation is possible before V-1 iterations
    // to improve time complexity
    bool updated = false;

    // WE will include vertices-1 edges to cover all vertices.
    for(int i = 0; i < vertices-1; i++)
    {
        updated = false;
        for(int j = 0; j < numEdges; j++)
        {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;

            if( distance[u] != INT_MAX && distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                parent_cost[v] = distance[u];
                updated = true;
            }

            if(updated == false)
                break;
        }
    }

    // Now check if we have a negative edge cycle by relaxing once more.
    for(int i=0; i < numEdges && updated == true; i++)
    {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;

        if(distance[u] != INT_MAX && distance[v] > distance[u] + weight )
        {
            cout<<"\n The graph has negative edge cycle.";
            return;
        }
    }

    // Printing the calculated shortest paths of all the vertices from source.
    for(int i = 1; i<vertices; i++)
    {
        cout<<"Cost to reach "<< i << " from source 0 = "<< distance[i] << endl;
    }
}

/*
    For given set of input:
    Enter number of vertices and edges of the graph : 5 8
    Enter source, destination and weight of edge : 0 1 2
    Enter source, destination and weight of edge : 0 2 4
    Enter source, destination and weight of edge : 1 2 5
    Enter source, destination and weight of edge : 1 3 8
    Enter source, destination and weight of edge : 1 4 9
    Enter source, destination and weight of edge : 2 4 6
    Enter source, destination and weight of edge : 2 3 11
    Enter source, destination and weight of edge : 3 4 1

    Following Output is produced: 
    Cost to reach 1 from source 0 = 2 
    Cost to reach 2 from source 0 = 4 
    Cost to reach 3 from source 0 = 10
    Cost to reach 4 from source 0 = 10 
*/

/*
    Time Complexity of Bellman-Ford Algorithm: O(V E)
    Space Complexity: O(E)
    where V and E are respectively the number of vertices and edges in the graph.
*/