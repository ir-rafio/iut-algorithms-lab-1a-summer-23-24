#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define ln '\n'

ll total = 0, num = 0;

void pre()
{
    fastio;


}

void dfs_visit(vector<ll>& visited, vector<vector<ll>>& adj, vector<ll> taka, int i) {
    if (visited[i] == 1) return;
    total += taka[i];
    num++;
    visited[i] = 1;
    for (int k = 0; k < adj[i].size(); k++) {
        if (visited[adj[i][k]] == 0) dfs_visit(visited, adj, taka, adj[i][k]);
    }
}

void solve(int tc)
{
    ll n, m, a, b, ans=1;
    cin >> n >> m;
    vector<ll> taka(n+1);
    vector<ll> visited(n+1, 0);
    vector<vector<ll>> adj(n+1, vector<ll>());
    set<ll> results;
    for (int i = 1; i <= n; i++) {
        cin >> taka[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            total = num = 0;
            dfs_visit(visited, adj, taka, i);
            if (total % num != 0) {
                ans = 0;
                break;
            }
            results.insert(total/num);
        }
    }
    if(ans == 0 || results.size() != 1) cout << "No";
    else cout << "Yes";
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
