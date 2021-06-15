/*
    Prim's Algorithm is used to find the minimum spanning tree from a graph. 
    Prim's algorithm finds the subset of edges that includes every vertex of the graph 
    such that the sum of the weights of the edges can be minimized.
*/

#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> prim(vector<vector<pair<int,int>>>& graph,
                                int start)
{
    vector<int> parent(graph.size(), -1);
    vector<int> key(graph.size(), INT_MAX);
    vector<bool> inMST(graph.size(), false);
    key[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, start));
    
    vector<tuple<int,int,int>> result;
    while (!pq.empty())
    {
        // Get min distance vertex from pq
        int v = pq.top().second;
        pq.pop();
        
        if (parent[v] != -1 && inMST[v] == false)
            result.emplace_back(make_tuple(parent[v], v, key[v]));

        inMST[v] = true;
        //Checking all the adjacent vertex
        for(auto x : graph[v])
        {
            int av = x.first;
            int weight = x.second;
            if (inMST[av] == false && key[av] > weight)
            {
                parent[av] = v;
                key[av] = weight;
                pq.push(make_pair(key[av],av));
            }
        }
    }
    return result;
}

void addEdge(vector<vector<pair<int,int>>>& graph,
             int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

int main()
{
    int V = 6;
    // pair of vertex, weight
    vector<vector<pair<int,int>>> graph(V, vector<pair<int,int>>(V));

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 0, 5, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 6);
    addEdge(graph, 1, 5, 4);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 3, 4, 2);

    vector<tuple<int,int,int>> res = prim(graph, 0);
    cout << "Minimum Spanning Tree: " << endl;
    for (tuple<int,int,int> t : res)
        cout << get<0>(t) << "-" << get<1>(t) << "," << get<2>(t) << endl;
    return 0;
}

/*
    Input: (0,1,4), (0,3,5), (0,5,3), (1,2,1), (1,3,3), (1,4,6), (1,5,4), (2,4,5), (2,5,6), (3,4,2)
    Output: Minimum Spanning Tree:
            0-5,3
            0-1,4
            1-2,1
            1-3,3
            3-4,2

    Time complexity - O(E + logV)
    Space complexity - O(n)
    Where E is number of edges and V is number of vertices.
*/
