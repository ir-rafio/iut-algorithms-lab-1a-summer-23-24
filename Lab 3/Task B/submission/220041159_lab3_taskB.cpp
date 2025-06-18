#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void solve()
{
    int n, p;
    cin >> n >> p;

    vector<vector<int>> adj(n);
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> component_sizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                size++;

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            component_sizes.push_back(size);
        }
    }

    long long total_pairs = (long long)n * (n - 1) / 2;
    for (int size : component_sizes) {
        total_pairs -= (long long)size * (size - 1) / 2;
    }

    cout << total_pairs << endl;
}

signed main()
{
    pre();

        // cout << "Case " << tc << ": ";
        solve();

    return 0;
}
