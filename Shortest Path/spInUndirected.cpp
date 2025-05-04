#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(int N, vector<vector<int>>& edges, int src) {
    // Step 1: Create adjacency list for undirected graph
    vector<int> adj[N];
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Initialize distance array with INF
    vector<int> dist(N, -1); // -1 means unreachable
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    // Step 3: Standard BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main() {
    int N = 6; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 5},
        {4, 5}
    };
    int src = 0;

    vector<int> result = shortestPath(N, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < N; ++i) {
        cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;
}
