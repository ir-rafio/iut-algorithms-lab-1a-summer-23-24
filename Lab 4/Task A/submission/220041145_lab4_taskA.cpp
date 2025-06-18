#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const LL INF=1e18;
vector<vector<pair<LL,int>>>adj;
void dijkstra(int s, vector<LL> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1); 
    d[s] = 0;
    set<pair<LL,int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
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
    }
    vector<LL>d(n+1);
    vector<int>p(n+1);
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
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}