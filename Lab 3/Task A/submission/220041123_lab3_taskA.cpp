#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ff first
#define ss second 
using ll = long long;



vector<vector<ll>> g ; 
vector<pair<ll,ll>> lead ;
vector<ll> vis  ; 
vector<ll> money ; 
void pre()
{
    fastio;

    
}
void f(ll node,ll par){
    if (vis[node]!=-1) return ; 
    vis[node] = 1 ; 
    lead[par].ff++ ;
    lead[par].ss+= money[node] ; 
    for(auto &ch:g[node]){
        f(ch,par) ; 
    }
}
void solve(int tc)
{
    // num of comp and tot = comp * k 
    ll n ,m ; cin >> n >> m ; 
    g.clear() ; 
    g.resize(n+1) ; 
    lead.clear()  ;
    lead.resize(n+1,{0,0}) ; 
    money.clear()  ;
    money.resize(n+1)  ;
    vis.clear()  ;
    vis.resize(n+1,-1) ; 
    for(ll i=1;i<=n;i++){   
        cin >> money[i] ;
    }
    for(ll i=0;i<m;i++){
        ll u , v ; cin >> u >> v ; 
        g[u].push_back(v) ; 
        g[v].push_back(u) ; 
    }
    for(ll i=1;i<=n;i++){
        if (vis[i]==-1){
            f(i,i) ; 
        }
    }
    int d = -1 ; 
    for(ll i=1;i<=n;i++){
        if (lead[i].ff==0) {
            continue ; 
        }
        if (lead[i].ss==0){
            if (d==-1) d = 0 ;
            else if (d!=0){
                cout << "Case " << tc << ": No" ; 
                return ; 
            }
            continue  ; 
        }
        if (lead[i].ss%lead[i].ff!=0){
            cout << "Case " << tc << ": No" ; 
            return ; 
        }
        else{
            if (d==-1){
                d = lead[i].ss/lead[i].ff ; 
            }
            else if (d!=lead[i].ss/lead[i].ff){
                cout << "Case " << tc << ": No" ; 
                return ; 
            }
        }
    }
    cout << "Case " << tc << ": Yes" ; 
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