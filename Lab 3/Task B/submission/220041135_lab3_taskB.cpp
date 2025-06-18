#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
bool visited[MAXN];
int n, p;

int dfs(int u) {
    visited[u] = true;
    int count = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            count += dfs(v);
        }
    }
    return count;
}

int main() {
    cin >> n >> p;

    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> groupSizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int size = dfs(i);
            groupSizes.push_back(size);
        }
    }

    long long totalPairs = 0;
    long long sum = 0;

    

    cout << totalPairs << endl;
    return 0;
}
