/*
   Breadth first search is a graph traversal algorithm that starts traversing the graph from root node and explores all the neighbouring nodes. 
   Then, it selects the nearest node and explore all the unexplored nodes. 
   The algorithm follows the same process for each of the nearest node until it finds the goal.
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void bfs(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        cout << v << "  ";
        q.pop();
        // Insert all adjacent nodes of v and mark them visited to avoid cycles.
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}
int main() {
    int V = 9;
    vector<int> graph[V];
    
    //Pair of Nodes
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);

    //Print BFS Traversal
    cout << "BFS traversal:" << "  ";
    bfs(graph, 0);
}


/*
    Time complexity - O(V + E)
    Space complexity - O(|V|) 
    Where E is number of edges and V is number of vertices.
*/  
