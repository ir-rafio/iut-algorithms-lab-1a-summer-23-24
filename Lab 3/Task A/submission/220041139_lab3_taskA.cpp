#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

pair<LL, LL> dfs(int u, vector<int> g[], vector<bool> &vis, vector<int> &money){
    if(vis[u]) return {0, 0};
    vis[u] = 1;
    pair<LL, LL> ret = {money[u], 1};
    for(auto v: g[u]){
        auto cur = dfs(v, g, vis, money);
        ret.first += cur.first;
        ret.second += cur.second;
    }
    return ret;
}

void solve(int tc){
    int n, m; cin >> n >> m;
    vector<int> g[n + 1], money(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> money[i];

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n + 1);
    vector<LL> comp;
    bool fl = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        auto [tot, people] = dfs(i, g, vis, money);
        if(tot % people) fl = 0;
        comp.push_back(tot / people);
    }
    sort(comp.begin(), comp.end());
    cout << "Case " << tc << ": ";
    if(fl and comp[0] == comp.back()) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    fastio;
    int tc, tt = 1;
    cin >> tt;
    for(tc = 1; tc <= tt; tc++){
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }
    return 0;
}
