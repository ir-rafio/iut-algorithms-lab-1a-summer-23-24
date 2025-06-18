#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int> >& graph, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

int journeyToMoon(int n, const vector<pair<int, int> >& astronautPairs) {
    vector<vector<int> > graph(n);
    for (const auto& p : astronautPairs) {
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
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

    return totalPairs - sameCountryPairs;
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int> > astronautPairs(p);

    for (int i = 0; i < p; ++i) {
        cin >> astronautPairs[i].first >> astronautPairs[i].second;
    }

    cout << journeyToMoon(n, astronautPairs) << endl;

    return 0;
}