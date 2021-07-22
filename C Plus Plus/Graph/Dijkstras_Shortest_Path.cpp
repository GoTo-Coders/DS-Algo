/*
    Dijkstra's Algrorithm is a greedy algorithm to find the shortest path between a
    source vertex and all the other vertices.UU
*/

// Implementation
#include<bits/stdc++.h>
using namespace std;


// Structure of Graph
class Graph{

    // Number of vertices in a graph
    int vertices;

    // Path matrix storing the distance between source and destination vertices.
    vector< vector<int> > path;

    public:
        Graph(int vertices){
            this->vertices = vertices;

            // Initailize the path matrix with the size of number of vertices,
            // with the inital value to be infinite i.e. INT_MAX
            path.assign(vertices, vector<int>(vertices, INT_MAX));

            // The shortest distance of a vertex to itself will always be zero.
            for(int i=0; i<vertices; i++){
                path[i][i] = 0;
            }
        }
        
        void addEdge(int, int, int);
        void dijkstra(int);
        int find_minimum(int[], bool[]);
        void print_min(int[], int);
};

// Method to add the edge between vertices with specified weight.
void Graph::addEdge(int source, int destination, int weight){
    path[source][destination] = weight;
}

// Method to find the minimum distance from the unvisited vertices.
int Graph::find_minimum(int distance[], bool sptSet[]){
    int min_index, min = INT_MAX;
    
    for(int i=0; i<vertices; i++){
        if(!sptSet[i] && distance[i]<=min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

// Method to implement Dijkstra's Algorithm.
void Graph::dijkstra(int source){
    // Array to store the minimum distance between source and vertex i, i.e. distance[i];
    int distance[vertices];

    // Boolean Array to know whether the vertex is processed or not.
    bool sptSet[vertices];


    // Initializing the arrays with respecitve infinite and false values.
    for(int i=0; i<vertices; i++){
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source to itself will always be zero;
    distance[source] = 0;

    // Find shortes path for all vertices
    for(int i=0; i<vertices; i++){

        // Pick the minimum distance vertex from the set of vertices, which are not 
        // yet processed. It is always source in first iteration.
        int u = find_minimum(distance, sptSet);

        // Set the picked vertex as processed.
        sptSet[u] = true;

        // Update distance value of adjacent vertices from picked vertex.
        for(int v = 0; v < vertices; v++)
        {
            // Update distance[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from source to v through u is
            // smaller than current value of distance[v]
            if(!sptSet[v] && path[u][v] != INT_MAX && distance[u] + path[u][v] < distance[v] )
                {
                    distance[v] = distance[u] + path[u][v];
                }
            }
    }

    print_min(distance, source);
}

// Method to print the minimum distance of each vertex from source.
void Graph::print_min(int distance[], int source){
    
    cout<<"The shortest path between the source vertex "<<source<<" and vertex \n";
    
    for(int i=0; i<vertices; i++){
        if(distance[i] == INT_MAX)
            cout<< i << " is : No Path"<<endl;
        else
            cout<< i << " is : " << distance[i]<<endl;
    }
}

int main(){
    // Object of graph with 5 vertices.
    Graph graph(5);

    // Adding edges to the graph.
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 4, 15);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 10);

// Calling the dijkstra algortihm to find the minimum distance from a vertex.
    graph.dijkstra(0);

    return 0;
}

/*
    Output:
        The shortest path between the source vertex 0 and vertex 
        0 is : 0
        1 is : 2
        2 is : 4
        3 is : 5
        4 is : 10
*/

/*
    Time Complexity of Dijkstra's ALgorithm is : O(V^2)
    Space Complexity - O(V)
*/