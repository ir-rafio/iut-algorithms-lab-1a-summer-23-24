#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod (ll)(1e9+7)
#define VAL (ll)1e3
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

ll vis[100001];

vector<ll> dijkstra(ll N, vector<vector<pair<ll, ll>>> &adj, ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    vector<ll> dist(N+1, LLONG_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        ll node = pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;

        for(auto [cst, v] : adj[node]) {
            if(dist[node] + cst < dist[v]) {
                dist[v] = dist[node] + cst;
                pq.push({dist[v], v});
            }
        }

    }

    return dist;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    for(ll i=0; i<m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    for(ll i=1; i<=n; i++) vis[i] = 0;

    vector<ll> ans = dijkstra(n, adj, 1);
    for(ll i=1; i<=n; i++) cout << ans[i] << " ";
}       

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T=1;
    //cin>>T;
    for(ll i=1; i<=T; i++)
    {
        solve();
    }
} 
