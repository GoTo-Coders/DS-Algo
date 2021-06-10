/*
  The Floyd Warshall algorithm is a shortest path algorithm for graphs.
  It computes the shortest path in a graph.
*/


#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &dist, const int V)
{
    /*
      nested loop for finding min. distance between i & j,
      and for each k fron 0 to V we are exploring all the possible value for k.
    */
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void addEdge(vector<vector<int>> &dist,
             int u, int v, int w)
{
    dist[u][v] = w;
}

int main()
{
    int V = 5;
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
  
    // pair of node, weight
    addEdge(dist, 0, 1, 7);
    addEdge(dist, 0, 4, -2);
    addEdge(dist, 0, 2, 5);
    addEdge(dist, 1, 3, 4);
    addEdge(dist, 1, 4, 6);
    addEdge(dist, 2, 1, 5);
    addEdge(dist, 3, 0, 2);
    addEdge(dist, 3, 2, -4);
    addEdge(dist, 4, 3, 8);
    for (int i = 0; i < V; i++)
        dist[i][i] = 0;

    floyd_warshall(dist, V);
    // Print shortest distances
    cout << "Shortest distance between all pairs: " << endl;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cout << i << "," << j << " : " << dist[i][j] << endl;
    cout << endl;

    return 0;
}

/*
  Time Complexity of Floyd Warshall is O(|V|3).
  Space Complexity of Floyd Warshall is O(|V|2).
  Where V is number of vertices.
*/
