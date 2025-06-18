#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& size) {
    visited[node] = true;
    size++;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, size);
        }
    }
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<vector<int>> adj(n);
    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false); 
    vector<int> groupSizes;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int size = 0;
            dfs(i, adj, visited, size);
            groupSizes.push_back(size);
        }
    }
    long long totalPairs = 0;
    long long sum = 0;
    for (int size : groupSizes) {
        totalPairs += sum * size;
        sum += size;
    }

    cout << totalPairs << endl;

    return 0;
}
