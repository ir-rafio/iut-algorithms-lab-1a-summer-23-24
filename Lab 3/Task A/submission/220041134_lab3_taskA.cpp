#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
using ll = long long;

ll arr[1002];
ll vis[1002];
vector<ll> adj[1002];
ll cnt, cost, avg;

void pre()
{
    fastio;


}

void dfs(ll u) {
    if(vis[u]) return;
    vis[u] = 1;
    cnt++;
    cost += arr[u];
    for(auto &it : adj[u]) {
        if(!vis[it]) dfs(it);
    }
}

void solve(int tc)
{
    ll n, m; cin >> n >> m;
    ll tot = 0;
    for(ll i=1; i<=n; i++) {
        cin >> arr[i];
        tot += arr[i];
        adj[i].clear();
    }
    for(ll i=0; i<m; i++) {
        ll x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(vis, 0, sizeof(vis));

    cout << "Case " << tc << ": ";

    avg = tot / n;
    if(tot % n) {
        cout << "No\n";
        return;
    }

    for(ll i=1; i<=n; i++) {
        cnt = 0;
        cost = 0;
        if(!vis[i]) {
            dfs(i);
            if(cnt * avg != cost) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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
        cout << '\n';
    }

    return 0;
}

