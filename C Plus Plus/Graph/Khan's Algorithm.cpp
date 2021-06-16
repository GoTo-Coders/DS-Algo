/*
    Topological sorting for Directed Acyclic Graph is a linear ordering of vertices 
    such that for every directed edge uv, vertex u comes before v in the ordering. 
    This is the algorithm of topological sort by Khan's algorithm
*/

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
}

vector<int> topological_sort(vector<int> graph[], int size)
{
    vector<int> result;
    queue<int> q;
    vector<int> indegree(size, 0);
    
    //Calculating Indegree for all the vertices.
    for (int i=0; i < size; i++)
        for (int j=0; j < graph[i].size(); j++)
            indegree[graph[i][j]]++;

    for (int i=0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
           q.push(i);
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        result.emplace_back(v);
        //Checking adjacent vertices
        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            indegree[*i]--;
            if (indegree[*i] == 0)
                q.push(*i);
        }
    }
    return result;
}

int main() {
    int size = 6;
    vector<int> graph[size];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);

    vector<int> result = topological_sort(graph, size);
    if (result.size() != size)
       cout << "Topological sort is not possible" << endl;
    else
    {
        cout << "Topological sort using Kahn's algorithm: " << endl;
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
    Input: (0,1),(0,2),(1,2),(1,3),(2,3),(2,4),(2,5)
    Output: Topological sort using Kahn's algorithm:
            0 1 2 3 4 5
    
    Time Complexity: O(V+E)
    Space Complexity: Θ(V)
    Where E is number of edges and V is number of vertices.
*/
