#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<LL>;

#define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
#define all(x) begin(x), end(x)

const LL INF = 1e18;
const LL MOD = 1e9 + 7;

void solve() {
  LL n, m; cin >> n >> m;
  vector<vector<pair<LL, LL>>> G(n + 1);
  while (m--) {
    LL u, v, w; cin >> u >> v >> w;
    G[u].push_back({v, w});
  }
  VI dis(n + 1, INF);
  priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<>> pq;
  pq.push({0, 1});
  dis[1] = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dis[u]) continue;
    for (auto &[v, w] : G[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }
  for (LL i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc = 1; //cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
}
