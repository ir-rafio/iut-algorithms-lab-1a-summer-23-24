#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using LL = long long;

void solve() {
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
    vector<int> componentSizes;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int size = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        size++;
                    }
                }
            }
            componentSizes.push_back(size);
        }
    }

    long long totalPairs = 0;
    long long sum = 0;
    for (int size : componentSizes) {
        totalPairs += sum * size;
        sum += size;
    }

    cout << totalPairs << endl;
}

int main() {
    fastio;

    solve();
    return 0;
}