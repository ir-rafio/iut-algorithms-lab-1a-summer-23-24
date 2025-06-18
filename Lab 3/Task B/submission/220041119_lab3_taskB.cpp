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

void dfs_visit(vector<ll>& visited, vector<vector<ll>>& adj, int i) {
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
    ll x = pairs.size();
    vector<ll> prefix(x, 0);
    for (int i = x-1; i >= 0; i--) {
        prefix[i] = pairs[i];
    }
    for (int i = x-2; i >= 0; i--) {
        prefix[i] += prefix[i+1];
    }
    for (int i = 0; i < pairs.size()-1; i++) {
        ans += (pairs[i]*prefix[i+1]);
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