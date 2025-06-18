#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

ll dijkstra(ll n, ll src, vector<vector<pair<ll, ll>>>& adj, vector<ll>& bicycles) {
    vector<ll> dist(n + 1, INF);
    dist[src] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, src});
    ll curr = bicycles[1];

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        curr = min(curr, bicycles[u]);

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + curr * w < dist[v]) {
                dist[v] = dist[u] + curr * w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n];
}

void solve() {

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<ll> bicycles(n + 1);

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        cin >> bicycles[i];
    }

    ll dist = dijkstra(n, 1, adj, bicycles);

    cout << dist << '\n';

}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
