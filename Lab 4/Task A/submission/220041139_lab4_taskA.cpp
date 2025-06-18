#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

#define PLL pair<long long, long long>

void solve(int tc)
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i <  m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    pq.push({0, 1});
    vector<LL> dis(n + 1, 1e18);
    while(pq.size()){
        auto [c, u] = pq.top();
        pq.pop();
        if(dis[u] <= c) continue;
        dis[u] = c;
        for(auto [v, w]: g[u]){
            if(dis[v] > c + w){
                pq.push({c + w, v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    cout << '\n';
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
