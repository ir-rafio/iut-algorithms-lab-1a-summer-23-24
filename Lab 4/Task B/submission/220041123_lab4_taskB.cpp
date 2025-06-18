#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ff first 
#define ss second 



void pre()
{
    fastio;

    
}
void solve(int tc)
{
    ll  n  , m ; cin >> n >> m ; 
    vector<vector<pll>> g(n+1) ; 
    vector<ll> dist(n+1,1e18) ; 
    vector<ll> cyc(n+1) ; for(ll i=1;i<=n;i++) cin >> cyc[i] ; 
    for(ll i=0;i<m;i++){
        ll u ,v,w; cin >> u >> v >> w ; 
        if (u==v) continue ; 
        g[u].push_back({v,w}) ; 
        g[v].push_back({u,w}) ;
    }
    priority_queue<pll,vector<pll>,greater<pll>> st ;  
    dist[1] = 0 ; st.push({0,1}) ; 
    while(!st.empty()){
        pll p = st.top() ; st.pop() ;
        ll u = p.ss  , len = p.ff ; 
        if (len>dist[u]) continue ; 
        for(auto &ch_p:g[u]){
            ll v = ch_p.ff ,  w  = ch_p.ss  ;
            if (len+w*cyc[u]>=dist[v]){
                continue ; 
            }
            dist[v] = len+w*cyc[u];  st.push({dist[v],v}) ; 
        }
    }
    cout << dist[n] ; 
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