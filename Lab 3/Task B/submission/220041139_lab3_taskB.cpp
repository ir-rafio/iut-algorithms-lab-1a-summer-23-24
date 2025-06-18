#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int dfs(int u, vector<int> g[], vector<bool> &vis){
    if(vis[u]) return 0;
    vis[u] = 1;
    int ret = 1;
    for(auto v: g[u]){
       ret += dfs(v, g, vis);
    }
    return ret;
}

void solve(int tc){
    int n, m; cin >> n >> m;
    vector<int> g[n];

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<LL> comp;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        comp.push_back(dfs(i, g, vis));
    }
    LL cur = 0, ans = 0;
    for(auto u: comp){
        ans += cur * u; cur += u;
    }
    cout << ans << '\n';
}

signed main(){
    fastio;
    int tc, tt = 1;
    // cin >> tt;
    for(tc = 1; tc <= tt; tc++){
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }
    return 0;
}
