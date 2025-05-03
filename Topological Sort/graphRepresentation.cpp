#include <iostream>
#include <vector>
using namespace std;

// Edge List → Adjacency List
vector<vector<int>> edgeListToAdjList(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n);
    for (auto &[u, v] : edges)
        adj[u].push_back(v);
    return adj;
}

// Adjacency List → Edge List
vector<pair<int, int>> adjListToEdgeList(vector<vector<int>> &adj) {
    vector<pair<int, int>> edges;
    for (int u = 0; u < adj.size(); ++u)
        for (int v : adj[u])
            edges.emplace_back(u, v);
    return edges;
}

// Adjacency List → Adjacency Matrix
vector<vector<int>> adjListToAdjMatrix(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            matrix[u][v] = 1;
    return matrix;
}

// Adjacency Matrix → Adjacency List
vector<vector<int>> adjMatrixToAdjList(const vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] == 1)
                adj[i].push_back(j);
    return adj;
}

// In-degree and Out-degree from Adjacency List
void computeDegreesFromAdjList(const vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &outDegree) {
    int n = adj.size();
    inDegree.assign(n, 0);
    outDegree.assign(n, 0);
    for (int u = 0; u < n; ++u) {
        outDegree[u] = adj[u].size();
        for (int v : adj[u])
            inDegree[v]++;
    }
}

// Helper: Print adjacency matrix
void printAdjMatrix(const vector<vector<int>> &matrix) {
    cout << "\nAdjacency Matrix:\n";
    for (auto &row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

// Helper: Print adjacency list
void printAdjList(const vector<vector<int>> &adj) {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < adj.size(); ++i) {
        cout << i << ": ";
        for (int v : adj[i])
            cout << v << " ";
        cout << endl;
    }
}

int main() {
    int n = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}};

    // Convert to Adjacency List
    auto adj = edgeListToAdjList(n, edges);

    // Convert to Matrix
    auto matrix = adjListToAdjMatrix(adj);

    // Compute Degrees
    vector<int> inDeg, outDeg;
    computeDegreesFromAdjList(adj, inDeg, outDeg);

    // Display
    printAdjList(adj);
    printAdjMatrix(matrix);

    cout << "\nIn-degrees:\n";
    for (int i = 0; i < n; ++i)
        cout << "Node " << i << ": " << inDeg[i] << endl;

    cout << "\nOut-degrees:\n";
    for (int i = 0; i < n; ++i)
        cout << "Node " << i << ": " << outDeg[i] << endl;

    return 0;
}
