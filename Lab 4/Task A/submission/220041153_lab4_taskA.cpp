#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<int> distance(n + 1, INF);
    distance[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > distance[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << distance[i] << " ";
    }
    cout << "\n";
    return 0;
}