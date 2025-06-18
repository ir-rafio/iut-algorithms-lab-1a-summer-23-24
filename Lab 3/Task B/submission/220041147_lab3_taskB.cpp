#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> graph(n);
    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> componentSizes;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int size = 0;
            dfs(i, graph, visited, size);
            componentSizes.push_back(size);
        }
    }

    long long totalPairs = (long long)n * (n - 1) / 2;
    long long sameCountryPairs = 0;
    for (int size : componentSizes) {
        sameCountryPairs += (long long)size * (size - 1) / 2;
    }
    cout << totalPairs - sameCountryPairs << endl;
    return 0;
}
