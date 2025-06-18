#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
vector<LL>comp;


void pre()
{
    fastio;

    
}
void dfs(vector<vector<LL>>& adj,vector<LL>& vis,LL s){
    comp.push_back(s);
    vis[s]=1;
    for(auto it : adj[s]){
        if(!vis[it]){
            dfs(adj,vis,it);       
        }
    }
}
void solve(int tc)
{
    LL n,m;
    cin>>n>>m;
    vector<vector<LL>> adj(n);
    vector<LL>vis(n,0);
    for(int i=0;i<m;i++){
        LL x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<LL>ex;
    for(LL i=0;i<n;i++){
        if(!vis[i]){
            comp.clear();
            dfs(adj,vis,i);
            LL d=comp.size();
            ex.push_back(d);
        }
    }
    LL res=n*(n-1)/2;
    for(auto it : ex){
        res-=(it*(it-1))/2;
        //cout<<res<<"\n";
    }
    cout<<res;
    

}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        //cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}