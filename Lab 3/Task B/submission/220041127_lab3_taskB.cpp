#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;



void pre()
{
    fastio;
}
int dfs(int node,vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    int size = 1;
    for (int v : adj[node]) {
        if (!visited[v]) {
            size += dfs(v, adj, visited);
        }
    }
    return size;
}

void solve(int tc)
{
    ll n,p;
    cin>>n>>p;
    vector<vector<int>> adj(n);

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n,false);
    vector<int> group_size;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            int size = dfs(i,adj,visited);
            group_size.push_back(size);
        }
    }

    ll total_pairs = n*(n-1)/2;
    ll invalid_pairs = 0;
    for(int size : group_size){
        invalid_pairs += (ll)(size*(size-1)/2);
    }
    total_pairs -= invalid_pairs;
    cout << total_pairs << '\n';

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