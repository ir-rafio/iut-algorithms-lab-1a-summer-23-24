#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
#define ll long long


ll cnt;
void pre()
{
    fastio;

    
}

void dfs_visit(vector<ll>& visited, vector<vector<ll>> adj, int i) {
    if (visited[i] == 1) return;
    visited[i] = 1;
    cnt++;
    for (auto k: adj[i]) {
        if (visited[k] == 0) dfs_visit(visited, adj, k);
    }
}

void solve(int tc)
{
    ll n, p, a, b, ans = 0;
    cin >> n >> p;
    vector<ll> pairs;
    vector<ll> ast(n);
    vector<ll> visited(n, 0);
    vector<vector<ll>> adj(n, vector<ll>());
    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cnt=0;
        if (visited[i] == 0) {
            dfs_visit(visited, adj, i);
            pairs.push_back(cnt);
        }
    }
    for (int i = 0; i < pairs.size(); i++) {
        for(int j = i+1; j < pairs.size(); j++) {
            ans += (pairs[i]*pairs[j]);
        }
    }
    cout << ans;
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}