#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const int INF = 1e9;

void pre() {
    fastio;
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);     }
 
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    
    vector<int> dist(n + 1, INF);  
    dist[1] = 0;)
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); 

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
 
        if(d > dist[u]) continue;
  
        for(auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
 
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
 
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}

signed main() {
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++) {
        solve(tc);
        cout << '\n';
    }

    return 0;
}

