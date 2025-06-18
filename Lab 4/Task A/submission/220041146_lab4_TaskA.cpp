#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> del(n + 1, INF);
    del[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [delay, u] = pq.top();
        pq.pop();

        if (delay > del[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (del[u] + w < del[v])
            {
                del[v] = del[u] + w;
                pq.push({del[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << del[i] << " ";
    }

    return 0;
}
