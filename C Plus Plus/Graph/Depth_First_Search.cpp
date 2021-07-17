/*
    Depth First Search Traversal is a popular traversal method in graph.
    It uses stack data structure for storing elements before output.
    The pseudo code for the traversal method is as follows:
        1. Initialize a boolean vecotr visited of size of number of vertices with false,
           which indicates whether a vertex is already visited or not.
        2. Push the source (generally 0 vertex) in the stack and set the visited[vertex] to true.
        3. Pop the top node.
            a. Print data.
            b. Find all the adjacent vertices with visited status false.
            c. Push them in the stack and set the visited status to true.
        4. Repeat step 3 until stack becomes empty.
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
        void addEdge(int, int);

        // Method to print the vertex of the graph in Depth First Search pattern.
        void Depth_First_Search(); 
};

void Graph::addEdge(int source, int destination){
    adjacency[source].emplace_back(destination);
}

void Graph::Depth_First_Search(){
    // Vector to contain visited status of vertices, initialized with false values.
    vector<bool> visited(adjacency->size(), false);

    //Stack to store the vertex.
    stack<int> stack;
    stack.push(0);
    visited[0] = true;

    // Continue loop, until stack becomes empty.
    while(!stack.empty()){

        int vertex = stack.top();
        cout << "V" << vertex << " ";
        stack.pop();

        // Find all the adjacent unvisited vertices and push the in the queue.
        for(auto i = adjacency[vertex].begin(); i != adjacency[vertex].end(); i++){
            if(!visited[*i]){
                stack.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main(){
    // Object of graph with 5 vertices.
    Graph graph(5);

    // Adding edges to the graph.
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    // Printing the vertices in Breadth First Search manner.
    cout<<"Depth First Search Traversal : ";
    graph.Depth_First_Search();
    return 0;
}

/*
    Time Complexity - O(|V| + |E|)
    Space Complexity - O(|V|)
    Where V is the number of vertices and E is the number of edges present in the graph.
*/