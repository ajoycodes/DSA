#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st) {
    vis[node] = true;
    for (auto it : adj[node]) {
        int v = it.first;
        if (!vis[v]) {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    vector<bool> vis(N, false);
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }

    // Convert unreachable nodes to -1
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) dist[i] = -1;
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 6; // number of nodes
    int M = 7; // number of edges

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {2, 3, 6},
        {4, 2, 2},
        {4, 5, 4},
        {5, 3, 1}
    };

    vector<int> result = shortestPath(N, M, edges);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": ";
        if (result[i] == -1) cout << "Unreachable";
        else cout << result[i];
        cout << '\n';
    }

    return 0;
}
