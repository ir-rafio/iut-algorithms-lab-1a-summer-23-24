#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

vector<vector<int>> adj;
vector<int> money;
vector<bool> visited;

pair<LL, int> dfs(int u) {
    visited[u] = true;
    LL sum = money[u];
    int count = 1;

    for (int v : adj[u]) {
        if (!visited[v]) {
            auto [s, c] = dfs(v);
            sum += s;
            count += c;
        }
    }

    return {sum, count};
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    money.resize(n);
    adj.assign(n, vector<int>());
    visited.assign(n, false);

    for (int i = 0; i < n; i++) cin >> money[i];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            auto [sum, count] = dfs(i);
            if (sum % count != 0) {
                possible = false;
                break;
            }
        }
    }

    cout << "Case " << tc << ": " << (possible ? "Yes" : "No");
}

void pre()
{
    fastio;
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        solve(tc);
        cout << '\n';
    }

    return 0;
}

