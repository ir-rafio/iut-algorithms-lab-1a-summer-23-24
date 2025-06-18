#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    int size = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        size++;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return size;
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> pairs(p);
    for (int i = 0; i < p; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    vector<vector<int>> graph(n);
    for (auto& p : pairs) {
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    vector<bool> visited(n, false);
    vector<int> componentSizes;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int size = bfs(i, graph, visited);
            componentSizes.push_back(size);
        }
    }
    return 0;
}
