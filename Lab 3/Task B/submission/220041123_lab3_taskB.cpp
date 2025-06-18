#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll= long long;



void pre()
{
    fastio;

    
}
vector<ll> grp_sz ; // grp_sz of parent 
vector<ll> vis  ;
vector<vector<ll>> g ; 
void f(ll node,ll par){
    if (vis[node]!=-1) return ;
    vis[node] = par ; 
    grp_sz[par]++ ; 
    for(auto ch:g[node]){
        f(ch,par) ; 
    }
}
void solve(int tc)
{
    ll n , m ; cin >> n >>m  ; 
    g.clear()  ; g.resize(n) ; 
    vis.clear() ;  vis.resize(n,-1);  
    grp_sz.clear() ; grp_sz.resize(n,0) ; 
    for(ll i=0;i<m;i++){
        ll u ,v ; cin >> u >> v ; 
        g[u].push_back(v)  ;
        g[v].push_back(u)  ;
    }
    for(ll i=0;i<n;i++){
        if (vis[i]==-1) f(i,i) ;
    }
    ll sm = n*(n-1) ;
    for(ll i=0;i<n;i++){
        sm -= grp_sz[vis[i]]-1 ;
    }
    cout << sm/2 ; 
}

signed main()
{
    pre();

    int tc, tt = 1;
    // cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}