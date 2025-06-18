#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vector<int> speed(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> speed[i];
        }

        vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

        dist[1][1] = 0;
        pq.emplace(0, 1, 1);

        while (!pq.empty()) {
            auto [time, u, bike_source] = pq.top();
            pq.pop();

            if (time > dist[u][bike_source]) continue;

            // 1. Move to neighbors using current bicycle
            for (auto &[v, w] : adj[u]) {
                ll new_time = time + (ll)w * speed[bike_source];
                if (new_time < dist[v][bike_source]) {
                    dist[v][bike_source] = new_time;
                    pq.emplace(new_time, v, bike_source);
                }
            }

            if (time < dist[u][u]) {
                dist[u][u] = time;
                pq.emplace(time, u, u);
            }
        }

        ll answer = INF;
        for (int i = 1; i <= n; ++i) {
            answer = min(answer, dist[n][i]);
        }

        cout << answer << "\n";
    }

    return 0;
}
