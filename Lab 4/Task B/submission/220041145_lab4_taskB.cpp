#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const LL INF=1e18;
vector<vector<pair<LL,int>>>adj;
void dijkstra(int s, vector<LL>& d, vector<LL>& p,vector<LL>& bikes) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s][s] = 0;
    priority_queue<tuple<LL,LL,LL>, vector<tuple<LL,LL,LL>>, greater<>> q;
    q.push({0,s,s});
    while (!q.empty()) {
        auto [dist,u,v] = q.top();
        q.pop();
        if (dist>d[u][v]) continue;
        if(dist<d[u][u]){
            d[u][u]=dist;
            q.push({dist,u,u})
        }
        for (auto it : adj[v]) {
            int to = it.first;
            LL len = it.second;
            LL dist2=dist+1LL*len*bikes[v];
            if (dist2 < d[to][v]) {
                d.
                q.push({d[to], to});
            }
        }
    }
}
void pre()
{
    fastio;

    
}

void solve(int tc)
{
    LL n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        LL x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    vector<LL>bikes(n+1);
    for(int i=1;i<=n;i++){
        cin>>bikes[i];
    }
    vector<LL>p(n+1);
    vector<vector<LL,LL>>d(n+1,vector<LL>(n+1,INF));
    dijkstra(1,d,p);
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    cout<<"\n";

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}