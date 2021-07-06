/*
  The Floyd Warshall algorithm is a shortest path algorithm for graphs.
  It computes the shortest path between two vertices in a graph.
*/


#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &distance, const int V)
{
    /*
      nested loop for finding minimum distance between i & j,
      and for each k fron 0 to V we are exploring all the possible value for k.
    */
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
}

void addEdge(vector<vector<int>> &distance,
             int initial, int destination, int weight)
{
    distance[initial][destination] = weight;
}

int main()
{
  // V - vertex
    int V = 5;
  
    vector<vector<int>> distance(V, vector<int>(V, INT_MAX));
  
    // pair of node, weight
    addEdge(distance, 0, 1, 7);
    addEdge(distance, 0, 4, -2);
    addEdge(distance, 0, 2, 5);
    addEdge(distance, 1, 3, 4);
    addEdge(distance, 1, 4, 6);
    addEdge(distance, 2, 1, 5);
    addEdge(distance, 3, 0, 2);
    addEdge(distance, 3, 2, -4);
    addEdge(distance, 4, 3, 8);
    for (int i = 0; i < V; i++)
        distance[i][i] = 0;

    floyd_warshall(distance, V);
    // Print shortest distances
    cout << "Shortest distance between all pairs: " << endl;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cout << i << "," << j << " : " << distance[i][j] << endl;
    cout << endl;

    return 0;
}

/*
  Time Complexity of Floyd Warshall is O(|V|^3).
  Space Complexity of Floyd Warshall is O(|V|^2).
  Where V is number of vertices.
*/
