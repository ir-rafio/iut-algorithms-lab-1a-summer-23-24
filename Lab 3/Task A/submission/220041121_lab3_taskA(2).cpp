#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> money;
vector<bool> visited;

void dfs(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, component);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        money.assign(n, 0);
        adj.assign(n, vector<int>());
        visited.assign(n, false);

        for (int i = 0; i < n; ++i) {
            cin >> money[i];
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component);
                long long total = 0;
                for (int person : component) {
                    total += money[person];
                }
                if (total % component.size() != 0) {
                    possible = false;
                    break;
                }
            }
        }

        cout << "Case " << tc << ": " << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}

