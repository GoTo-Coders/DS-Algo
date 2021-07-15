/*
    Breadth First Search Traversal is a popular traversal method in graph.
    It uses queue data structure for storing elements before output.
    The pseudo code for the traversal method is as follows:
        1. Initialize a boolean vecotr visited of size of number of vertices with false,
           which indicates whether a vertex is already visited or not.
        2. Push the source (generally 0 vertex) in the queue and set the visited[vertex] to true.
        3. Pop the front node.
            a. Print data.
            b. Find all the adjacent vertices with visited status false.
            c. Push them in the queue and set the visited status to true.
        4. Repeat step 3 until queue becomes empty.
        5. Finish and Return.
*/

// Implementation
#include<bits/stdc++.h>
using namespace std;

// Structure of Graph
class Graph{

    // Number of vertices
    int vertices;

    // Will contain the vertices which are adjacent to other.
    vector<int> *adjacency;

    public:
        // Constructor
        Graph(int vertices){
            this->vertices = vertices;
            
            // Creating a array of  vector to store the adajacent vertices with
            // respect to the index of source vertex.
            adjacency = new vector<int>[vertices];
            
        }

        // Method to add a directed edge bvetween two vertices.
        void addedge(int , int);

        // Method to print the vertex of the graph in Breadth First Search pattern.
        void breadth_first_search();
};

void Graph::addedge(int source, int destination){
    adjacency[source].emplace_back(destination);
}


void Graph::breadth_first_search(){
    // Vector to contain visited status of vertices, initialized with false values.
    vector<bool> visited(adjacency->size(), false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    // Continue loop, until queue becomes empty.
    while(!q.empty()){
        int vertex = q.front();
        cout<< "V" << vertex <<" ";
        q.pop();

        // Find all the adjacent unvisited vertices and push the in the queue.
        for(auto i = adjacency[vertex].begin(); i != adjacency[vertex].end(); i++){
            if(!visited[*i]){
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}


int main(){
    // Object of graph with 5 vertices.
    Graph graph(5);

    // Adding edges to the graph.
    graph.addedge(0, 1);
    graph.addedge(0, 2);
    graph.addedge(1, 2);
    graph.addedge(1, 4);
    graph.addedge(1, 3);
    graph.addedge(2, 4);
    graph.addedge(3, 4);

    // Printing the vertices in Breadth First Search manner.
    cout<<"Breadth First Search Traversal : ";
    graph.breadth_first_search();
    
    
/*
    Time Complexity - O(|V| + |E|)
    Space Complexity - O(|V|)
    where V is the number of vertices and E is the number of edges present in the graph.
*/