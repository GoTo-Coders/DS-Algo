/*
    Dijkstra's Algorithm finds the shortest path between a given node (which is called the "source node") and all other nodes in a graph.
    This algorithm uses the weights of the edges to find the path that minimizes the total distance (weight) between the source node and all other nodes.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start)
{
    vector<int> dist(graph.size(), INT_MAX);

    // <weight, vertex> pair. First element of priority queue will be the minimum
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Add start to pq, where distance is 0
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        // Get min distance vertex from pq
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            // If the distance to v is shorter
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

int main()
{
    // pair of node, weight
    vector<vector<pair<int, int>>> graph(9, vector<pair<int, int>>(9));

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 7, 6);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 15);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 8, 6);
    addEdge(graph, 2, 5, 7);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 14);
    addEdge(graph, 5, 6, 12);
    addEdge(graph, 6, 7, 11);
    addEdge(graph, 6, 8, 5);
    addEdge(graph, 7, 8, 5);

    vector<int> dist = dijkstra(graph, 0);
    // Print shortest distances
    cout << "Vertex      Distance from Source" << endl;
    for (int i = 0; i < 9; ++i)
        cout << i << "\t\t" << dist[i] << endl;
    return 0;
}

/*
    Time complexity - O(V + E log V) 
    Space complexity - O(|V| + |E|)
    Where E is number of edges and V is number of vertices.
*/
