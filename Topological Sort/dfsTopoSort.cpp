#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

void dfsTopoSortUtil(int node, vector<bool>& visited, stack<int>& Stack, vector<vector<int>>& adj) {
    visited[node] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsTopoSortUtil(neighbor, visited, Stack, adj);
        }
    }

    // Push current vertex to stack which stores the result
    Stack.push(node);
}

void dfsTopoSort(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    stack<int> Stack;

    // Create the adjacency list
    // and calculate indegrees
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    for(int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsTopoSortUtil(i, visited, Stack, adj);
        }
    }

    vector<int> topoOrder;

    for (int i = 0; i < n; i++) {
        if (!Stack.empty()) {
            topoOrder.push_back(Stack.top());
            Stack.pop();
        }
    }

    
    // Check if topological sort is possible
    if(topoOrder.size() != n){
        cout << "Cycle detected, topological sort not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for(int node: topoOrder){
            cout << node << " ";
        }
        cout << endl;
    }

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 6; // Number of nodes
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };
    // Example edges for a directed graph
    // You can modify this to test with different graphs
    // Call the Kahn's algorithm function
    dfsTopoSort(n, edges);
    

    return 0;
}