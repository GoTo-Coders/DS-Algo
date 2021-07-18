/*
    Floyd Warshall Shortest Path Algorithm is applied to find the shortest distance 
    between two vertices in a graph.

    It is based on a formula given by floyd-warshall i.e.
        distance(k)[i][j] = minimum of (distance(k-1)[i][j] , distance(k-1)[i][k] + distance(k-1)[k][j])

    where, i and j are the source and destination vertex respectively and,
    k is the order of path matrix formed.

*/

// Implementation
#include<bits/stdc++.h>
using namespace std;

// Structure of Graph
class Graph{

    // Number of vetices in a graph
    int vertices;

    // Path matrix for graph.
    vector< vector<int> > path;

    // Matrix to store the minimum distance between the two vertices.
    vector< vector<int> > min_distance;

    public:
        // Constructor
        Graph(int vertices){
            this->vertices = vertices;

            // Initailize the path matrix with the size of number of vertices,
            // with the inital value to be infinite i.e. INT_MAX
            path.assign(vertices, vector<int>(vertices, INT_MAX));

            min_distance.assign(vertices, vector<int>(vertices, INT_MAX));

            // The shortes distance of a vertex to itself will always be zero.
            for(int i = 0; i<vertices; i++){
                path[i][i] = 0;
                min_distance[i][i] = 0;
            }
        }

        void floyd_warshall();
        void addEdge(int, int, int);
        void printGraph();
        void printMinimumDistance();
};

// Method to add edge between two vertices with specific weight
void Graph::addEdge(int source, int destination, int weight){
    path[source][destination] = weight;
}

// Mehtod to find the shortet distance matrix using floyd-warshall algorithm
void Graph::floyd_warshall(){

    // Copying the path matrix to the min_distance matrix
    min_distance = path;

    // k - to determine the order of matrix
    for(int k=0; k<vertices; k++){

        // i - to determine to source vertex
        for(int i=0; i<vertices; i++){

            // j-  to determine the destination vertex
            for(int j=0; j<vertices; j++){

                // Condition for implementation of formula
                if (min_distance[i][j] > (min_distance[i][k] + min_distance[k][j])
                    && (min_distance[k][j] != INT_MAX
                        && min_distance[i][k] != INT_MAX))
                    min_distance[i][j] = min_distance[i][k] + min_distance[k][j];
            }
        }
    }
}

// Method to print the min_distance matrix
void Graph::printGraph(){
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(path[i][j] == INT_MAX)
                cout<<"INF  ";
            else    
                cout<<path[i][j]<<"  ";
        }
        cout<<endl;
    }
}

// Method to print the min_distance matrix
void Graph::printMinimumDistance(){
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(min_distance[i][j] == INT_MAX)
                cout<<"INF  ";
            else    
                cout<<min_distance[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    // Object of graph with 5 vertices.
    Graph graph(5);

    // Adding edges to the graph.
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 4, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 10);

    cout<<"\nDistance from each vertex : "<<endl;
    graph.printGraph();
    graph.floyd_warshall();
    cout<<"\nShortest distance by Floyd Wrashall Algorithm is : "<<endl;
    graph.printMinimumDistance();
    return 0;
}

/*
    Time Complexity of Floyd Warshall is O(|V|^3).
    Space Complexity of Floyd Warshall is O(|V|^2),
    where V is number of vertices.
*/
