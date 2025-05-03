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

void kahnTopologicalSort(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);

    // Create the adjacency list
    // and calculate indegrees
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    // Initialize the queue with nodes having indegree 0
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topoOrder;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);  

        for(int neighbor: adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
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
    kahnTopologicalSort(n, edges);
    

    return 0;
}