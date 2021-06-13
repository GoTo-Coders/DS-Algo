/*  
    Depth-first search is an algorithm for traversing or searching tree or graph data structures.      
    The algorithm starts at the root node and explores as far as possible along each branch before backtracking. 
*/    


#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void dfs(vector<int> graph[], vector<bool>& visited, int node)
{
    //Using Recursive Approach
    visited[node] = true;
    cout << node << "  ";
    for (auto i = graph[node].begin(); i != graph[node].end(); i++) {
        if (!visited[*i])
           dfs(graph, visited, *i);
    }
}

int main() {
    int V = 9;
    vector<int> graph[V];

    //Pair of nodes
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);

    cout << "DFS traversal:" << "  ";
    vector<bool> visited(graph->size(), false);
    dfs(graph, visited, 0);

    return 0;
}
 

/*     
    Input:(0,1),(0,3),(1,2),(2,3),(2,5),(3,4),(4,5),(4,7),(5,6),(6,7)     
    Output:0 1 2 3 4 5 6 7          
 
    Time Complexity: O(|V|+|E|),  where V is the number of vertexes and E is the number of edges.     
    Space Complexity:O(h), where h is the maximum height of the tree.  
*/
