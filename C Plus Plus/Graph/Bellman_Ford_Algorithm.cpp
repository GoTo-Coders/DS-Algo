/*
    The Bellman–Ford algorithm is an algorithm that computes shortest paths 
    from a single source vertex to all of the other vertices in a weighted digraph.
*/


#include <bits/stdc++.h>
using namespace std;

bool bellman_ford(map<pair<int,int>,int>& edges,
                  vector<int>& dist,
                  int V)
{
    for (int i=1; i < V; i++)
    {
        for (auto e : edges)
        {
            int u = e.first.first;
            int v = e.first.second;
            int weight = e.second;
            if (dist[v] > dist[u] + weight)
               dist[v] = dist[u] + weight;
        }
    }
    
    //If any negative weighted cycle are present
    for (auto e : edges)
    {
        int u = e.first.first;
        int v = e.first.second;
        int weight = e.second;
        if (dist[v] > dist[u] + weight)
            return false;
    }
    return true;
}

void addEdge(map<pair<int,int>,int>& edges,
             int u, int v, int w)
{
    edges[make_pair(u,v)] = w;
}

int main()
{
    int V = 5;
    map<pair<int,int>,int> edges;
    
    // pair of vertex, weight
    addEdge(edges, 0, 1, 6);
    addEdge(edges, 0, 2, 4);
    addEdge(edges, 1, 3, 4);
    addEdge(edges, 1, 4, 5);
    addEdge(edges, 1, 2, 4);
    addEdge(edges, 2, 1, 6);
    addEdge(edges, 2, 4, 4);
    addEdge(edges, 2, 3, 4);
    addEdge(edges, 4, 3, -4);

    //Intialising distance to infinity
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    bool res = bellman_ford(edges, dist, V);
    if (!res)
        cout << "Negative weight cycle exist" << endl;
    else
    {
        cout << "Shortest path distance: " << endl;
        for (int i=0; i < V; i++)
            cout << "\t0-" << i << " : " << dist[i] << endl;
    }
}


/*
    Input: (0,1,6),(0,2,4),(1,3,4),(1,4,5),(1,2,4),(2,1,6),(2,4,4),(2,3,4),(4,3,-4)
    
    Output:
        Shortest path distance:
            0-0 : 0
            0-1 : 6
            0-2 : 4
            0-3 : 4
            0-4 : 8
    
    Time complexity: O(VE)
    Space complexity: O(V)
    Where E is number of edges and V is number of vertices.
*/
