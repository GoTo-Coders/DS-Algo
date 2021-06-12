/*
    A Hamiltonian Path is a path that visits each vertex of the graph exactly once,
    and when we connect the last edge to the first edge then it become Hamiltonian cycle.
*/


#include <bits/stdc++.h>
#define V 7
using namespace std;

bool hamiltonianCycle(vector<int> graph[], vector<bool> visited, vector<int>& path, int v)
{
    if (path.size() == V)
        return true;
    for (auto av : graph[v])
    {
        if (visited[av] == false)
        {
            visited[av] = true;
            path.emplace_back(av);
            if (hamiltonianCycle(graph, visited, path, av))
                return true;
            //Marking the visited array false and removing it from path array.    
            visited[av] = false;
            path.pop_back();
        }
    }
    return false;
}

void addEdge(vector<int> graph[],
             int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

int main()
{
    
    vector<int> graph[V];
    
    //Edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);

    vector<bool> visited(V, false);
    vector<int> path;
    path.emplace_back(0);
    visited[0] = true;
    
    cout << "Hamiltonian Cycle: ";
    if (hamiltonianCycle(graph, visited, path, 0))
    {
        //Printing path
        for (int i : path)
            cout << i << "  ";
        //Printing path 0 because it will ba a close loop.    
        cout << path[0] << endl;
    }
    else
        cout << "0" << endl;
    return 0;
}


/*
  Sample Input/Output:
    input: (0,1), (0,3), (0,4), (0,5), (1,2), (1.4), (1,5), (2,3), (2,4), (2,6), (3,4), (3,6)
    output: Hamiltonian Cycle: 0 3 6 2 4 1 5 0 
*/    
