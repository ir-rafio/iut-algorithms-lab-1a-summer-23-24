#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

vector<ll> dijkstra(ll n, ll src, vector<vector<pair<ll, ll>>>& adj) {
    vector<ll> dist(n + 1, INF);
    dist[src] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }


    vector<ll> dist = dijkstra(n, 1, adj);

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}


