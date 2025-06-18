#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
vector<LL>comp;


void pre()
{
    fastio;

    
}
void dfs(vector<vector<LL>>& adj,vector<LL>& vis,LL s,vector<LL>& v){
    comp.push_back(s);
    vis[s]=1;
    for(auto it : adj[s]){
        if(!vis[it]){
            dfs(adj,vis,it,v);       
        }
    }
}
void solve(int tc)
{
    LL n,m;
    cin>>n>>m;
    vector<LL>v(n);
    vector<vector<LL>> adj(n+1);
    vector<LL>vis(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<m;i++){
        LL x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    LL avg=0;
    bool x=false;
    for(LL i=1;i<=n;i++){
        if(!vis[i]){
            comp.clear();
            dfs(adj,vis,i,v);
        }
        LL sum=0;
        for(auto it : comp){
            sum+=v[it-1];
        }
        if(sum%comp.size()!=0){
            cout<<"No";
            return;
        }
        if(!x){
            avg=sum/comp.size();
            x=true;
        }
        LL d=sum/comp.size();
        if(d!=avg){
            cout<<"No";
            return;
        }

    }
    cout<<"Yes";

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}