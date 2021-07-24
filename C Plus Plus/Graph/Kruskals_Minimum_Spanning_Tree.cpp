/*
    Kruskal's Algorithm is based on greedy approach to find the minimum spanning tree.
    The pseudocode for the algorithm is:
        a. Take input of edges with all necessities i.e. source, destination and weight.
        b. Sort the array of input edges from step a).
        c. Pick the edges one by one from input array
        d. Apply find and union on the edge
        e. If the edge forms cycle in graph, discard it
        f. Else, include it in the MST(Minimum Spanning Tree)
        g. Repeat steps c - f until the number of edges = number of vertices - 1.
        h. Finish and Return
*/

// Implementaion
#include <bits/stdc++.h>
using namespace std;

// Strcuture to store all the elements of edge in single entity.
class Edge
{
public:
    int source;
    int destination;
    int weight;
};

// Method to compare the weights of two edges
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

// Method to find the parent of an edge
int findParent(int vertex, int parent[])
{
    if (parent[vertex] == vertex)
        return vertex;

    return findParent(parent[vertex], parent);
}

// Method to print the minimum spanning tree
void printMST(Edge *MST, int size)
{
    cout << "Minimum Spanning Tree of provided graph is:" << endl;
    cout << "Edge  \t  Weight";

    for (int i = 0; i < size; i++)
    {
        cout << MST[i].source << " - " << MST[i].destination << "\t" << MST[i].weight << endl;
    }
}

// Method to implement Kruskal's Algorithm
void kruskals(Edge *graph, int vertices, int edges)
{
    // Sorting the array of vertices with respect to their weights in
    // increasing order, to pick the edges acoordingly.
    sort(graph, graph + vertices, compare);

    // MST - Minimum Spanning Tree to store the included edges in the MST
    Edge *MST = new Edge[vertices - 1];

    // An array to maintain and represent the set of vertices.
    int *parent = new int[vertices];

    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    int count = 0, i = 0;

    while (count != vertices - 1)
    {
        Edge currentEdge = graph[i];

        // The code below uses Unio-Find algorithm to detect cycle in graph
        // which says that if both vertices belongs to the same set than there is a 
        // cycle in a graph.
        // Below is the find operation.
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.destination, parent);

        // This is the union operation.
        // If both vertices does not belong to same set, then include the edge in the MST
        // and perform the union on them.
        if (sourceParent != destParent)
        {
            MST[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++;
    }

    // Print the calculated MST
    printMST(MST, vertices - 1);
}

int main()
{
    int vertices, numEdges;

    // Taking values for number of vertices and number of edges present in the graph.
    cout << "Enter number of vertices : ";
    cin >> vertices;
    cout << "Enter number of edges : ";
    cin >> numEdges;

    // Craeting an array of size numEdge and type edges to store the edges with
    // adequate information such as source, destination. and weight.
    Edge *inputGraph = new Edge[numEdges];

    // Taking input for adding edges and their weights.
    for (int i = 0; i < numEdges; i++)
    {
        int source, destination, weight;
        cout << "Enter source, destination and weight of edge : ";
        cin >> source >> destination >> weight;

        inputGraph[i].source = source;
        inputGraph[i].destination = destination;
        inputGraph[i].weight = weight;
    }

    // Calling Kruskal's method to find minimum spanning tree
    kruskals(inputGraph, vertices, numEdges);

    return 0;
}

/*
For Input:
    Enter number of vertices : 5
    Enter number of edges : 8
    Enter source, destination and weight of edge : 0 2 1
    Enter source, destination and weight of edge : 0 1 2
    Enter source, destination and weight of edge : 1 2 3
    Enter source, destination and weight of edge : 2 3 4
    Enter source, destination and weight of edge : 1 3 5
    Enter source, destination and weight of edge : 2 4 6
    Enter source, destination and weight of edge : 1 4 8
    Enter source, destination and weight of edge : 3 4 10

The Output is:
    Minimum Spanning Tree of provided graph is:
    Edge      Weight
    0 - 2       1
    0 - 1       2
    2 - 3       4
    2 - 4       6
*/

/*
    Time Complexity of Kruskal's Algorthm is: O(E log V)
    Space Complexity: O(V)
    where V and E are the number of vertices and edges in the graph respectively.
*/