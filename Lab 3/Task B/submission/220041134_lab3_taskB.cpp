#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
using ll = long long;

ll vis[100002];
vector<ll> adj[100002];
ll cnt;

void pre()
{
    fastio;
}

void dfs(ll u) {
    if(vis[u]) return;
    vis[u] = 1;
    cnt++;
    for(auto &it : adj[u]) {
        if(!vis[it]) dfs(it);
    }
}

void solve(int tc)
{
    ll n, m; cin >> n >> m;
    for(ll i=0; i<n; i++) {
        adj[i].clear();
    }
    for(ll i=0; i<m; i++) {
        ll x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(vis, 0, sizeof(vis));

    vector<ll> fnl;
    for(ll i=0; i<n; i++) {
        cnt = 0;
        if(!vis[i]) dfs(i);
        if(cnt > 0) fnl.push_back(cnt);
    }

    ll N = fnl.size();
    ll suf[N+1];
    suf[N] = 0;
    for(ll i=N-1; i>=0; i--) suf[i] = suf[i+1] + fnl[i];
    ll ans = 0;
    for(ll i=0; i<N; i++) {
        ans += fnl[i]*suf[i+1];
    }

    //for(ll i=0; i<=N; i++) cout << suf[i] << " ";

    cout << ans << "\n";
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

