#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

#define TLL tuple<long long, long long, long long>

const int N = 1e3 + 10;
const LL INF = 1e18;
LL dis[N][N];

void solve(int tc)
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i <  m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][s[j]] = INF;
        }
    }
    priority_queue<TLL, vector<TLL>, greater<TLL>> pq;
    pq.push({0, 1, s[1]});

    while(pq.size()){
        auto [c, u, b] = pq.top();
        pq.pop();
        if(dis[u][b] <= c) continue;
        dis[u][b] = c;
        b = min(b, 1LL * s[u]);
        for(auto [v, w]: g[u]){
            if(dis[v][b] > c + w * b){
                pq.push({c + w * b, v, b});
            }
        }
    }
    LL ans = 1e18;
    for(int i = 1; i <= n; i++){
        ans = min(ans, dis[n][s[i]]);
    }

    cout << ans << '\n';
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
    }

    return 0;
}
