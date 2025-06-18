#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
LL inf=numeric_limits<long long>::max();
void dijkstra(int n, vector<vector<pair<int, int>>> &adj, vector<LL> &dist) {
    dist[1] = 0;
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] != inf && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}


void pre()
{
    fastio;


}

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    vector<LL> dist(n + 1, inf);
    dijkstra(n, adj, dist);

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    pre();

        solve();

    return 0;
}
