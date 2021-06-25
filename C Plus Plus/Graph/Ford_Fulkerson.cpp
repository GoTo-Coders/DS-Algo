/*
    The Ford–Fulkerson algorithm is a greedy algorithm that computes the maximum flow in a flow network. 
    It is sometimes called a "method" instead of an "algorithm" as the approach to finding augmenting paths 
    in a residual graph is not fully specified or it is specified in several implementations with different running times.
*/

#include <bits/stdc++.h>
using namespace std;

//BFS traversal
int bfs(int start, int last, vector<int> &parent, vector<vector<int>> &nGraph)
{
    fill(parent.begin(), parent.end(), -1);
    int v = nGraph.size();
    parent[start] = -2;
    queue<pair<int, int>> q;
    q.push({start, INT_MAX});

    while (!q.empty())
    {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        //Enqueue all adjacent nodes of v
        for (int av = 0; av < v; av++)
        {
            if (u != av && parent[av] == -1 && nGraph[u][av] != 0)
            {
                parent[av] = u;
                int min_capacity = min(capacity, nGraph[u][av]);
                if (av == last)
                    return min_capacity;
                q.push({av, min_capacity});
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>> &graph, int start, int last)
{
    vector<int> parent(graph.size(), -1);
    //Creating another graph which is equal to original graph
    vector<vector<int>> nGraph = graph;
    int min_capacity = 0, max_flow = 0;
    //Doing BFS traversal to find out minimum capacity
    while (min_capacity = bfs(start, last, parent, nGraph))
    {
        max_flow += min_capacity;
        int u = last;
        while (u != start)
        {
            int v = parent[u];
            nGraph[u][v] += min_capacity;
            nGraph[v][u] -= min_capacity;
            u = v;
        }
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
    int V = 6;
    //Creating graph in the form of adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    //Edges and Weights
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 3, 4);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 5, 3);
    addEdge(graph, 3, 4, 8);
    addEdge(graph, 4, 5, 5);

    cout << "Maximum Flow: " << ford_fulkerson(graph, 0, 5) << endl;
    return 0;
}

/*
    Input: (0,1,4), (0,3,4), (1,2,5), (2,3,5), (2,5,3), (3,4,8), (4,5,5)
    Output: Maximum Flow: 8

    Time complexity: O(Ef), where f is the maximum flow and E is the set of edges in the ngraph
    Space complexity: Θ(E + V), Where E is number of edges and V is number of vertices
*/
