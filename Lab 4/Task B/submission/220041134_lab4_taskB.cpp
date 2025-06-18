#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod (ll)(1e9+7)
#define VAL (ll)1e3
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    for(ll i=0; i<m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    vector<ll> s(n + 1);
    for(ll i=1; i<=n; i++) cin >> s[i];

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

    dist[1][1] = 0;
    pq.push({0, {1, 1}});

    while(!pq.empty()) {
        auto [curr, state] = pq.top();
        auto [city, bicycle] = state;
        pq.pop();

        if (curr > dist[city][bicycle]) continue;

        for(auto [w, next] : adj[city]) {
            ll time = curr + 1ll * s[bicycle] * w;
            if(time < dist[next][bicycle]) {
                dist[next][bicycle] = time;
                pq.push({time, {next, bicycle}});
            }
        }

        if(curr < dist[city][city]) {
            dist[city][city] = curr;
            pq.push({curr, {city, city}});
        }
    }

    ll ans = LLONG_MAX;
    for(int i=1; i<=n; i++) {
        ans = min(ans, dist[n][i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T=1;
    cin>>T;
    for(ll i=1; i<=T; i++)
    {
        solve();
    }
}

