#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<int> money(n);
    LL total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> money[i];
        total += money[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (total % n != 0) {
        cout << "Case " << tc << ": No";
        return;
    }

    LL target = total / n;
    vector<bool> visited(n, false);
    bool possible = true;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            LL sum = 0;
            int count = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                sum += money[u];
                count++;

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            if (sum % count != 0 || sum / count != target) {
                possible = false;
                break;
            }
        }
    }

    cout << "Case " << tc << ": " << (possible ? "Yes" : "No");
}

int main() {
    fastio;

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++) {
        solve(tc);
        cout << '\n';
    }

    return 0;
}