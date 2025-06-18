#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
using ll = long long;
typedef pair<ll, ll> pll;

void pre()
{
    fastio;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pll>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<LL> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    priority_queue< pll, vector<pll>, greater <pll> > pq;
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        LL currrentDist = pq.top().first;
        LL u = pq.top().second;
        pq.pop();

        if(currentDist > dist[u]){
            continue;
        }

        for (auto &edge : adj[u])
        {
            LL v = edge.first;
            LL weight = edge.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(dist[v], v);
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout<<dist[i]<<" ";
    }
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for (tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}