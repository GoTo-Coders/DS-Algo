//Dinic's algorithm is a strongly polynomial algorithm for computing the maximum flow in a flow network

#include <bits/stdc++.h>
using namespace std;
#define V 6

//BFS traversal
bool bfs(vector<vector<int>> &nGraph, vector<int> &level, int source, int sink)
{
    fill(level.begin(), level.end(), -1);
    level[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (u != v && nGraph[u][v] > 0 && level[v] < 0)
            {
                // Saving the parents of each vertices
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] < 0 ? false : true;
}

// Checking if we can pass more flow
int Flow(vector<vector<int>> &nGraph, vector<int> &level, vector<int> &count, int u, int sink, int flow)
{
    if (u == sink)
        return flow;

    if (count[u] == nGraph[u].size())
        return 0;

    // Traversing each adjacent edges
    for (int v = 0; v < V; v++)
    {
        if (nGraph[u][v] > 0)
        {
            count[u]++;
            if (level[v] == level[u] + 1)
            {
                // finding minimum flow
                int curr_flow = min(flow, nGraph[u][v]);

                int min_cap = Flow(nGraph, level, count, v, sink, curr_flow);
                if (min_cap > 0)
                {
                    nGraph[u][v] -= min_cap;
                    nGraph[v][u] += min_cap;
                    return min_cap;
                }
            }
        }
    }
    return 0;
}

int dinic_algorithm(vector<vector<int>> &graph, int source, int sink)
{
    if (source == sink)
        return -1;

    int max_flow = 0;
    vector<vector<int>> nGraph = graph;
    vector<int> level(V, -1);

    while (bfs(nGraph, level, source, sink) == true)
    {
        // storing how many neighbors are visited
        vector<int> count(V, 0);

        // adding max_flow
        while (int flow = Flow(nGraph, level, count, source, sink, INT_MAX))
            max_flow += flow;
    }
    return max_flow;
}

void addEdge(vector<vector<int>> &graph,
             int u, int v, int w)
{
    graph[u][v] = w;
}

int main()
{
    vector<vector<int>> graph(V, vector<int>(V, 0));

    addEdge(graph, 0, 1, 9);
    addEdge(graph, 0, 2, 7);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 13);
    addEdge(graph, 3, 5, 9);
    addEdge(graph, 4, 5, 14);

    cout << "Maximum flow: " << dinic_algorithm(graph, 0, 5);
    return 0;
}

/*
    Input: (0,1,9)(0,2,7)(1,3,7)(1,4,5)(2,4,13)(3,5,9)(4,5,14)
    output: Maximum flow: 16

    Time complexity: Θ(EV²)
    Space complexity: Θ(E + V)
    Where E is number of edges and V is number of vertices.
*/
