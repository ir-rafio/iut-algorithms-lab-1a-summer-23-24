#include <bits/stdc++.h>
using namespace std;

// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;

const ll INF=1e18;

typedef pair<ll,ll> pr;

void dijkstra(ll src,ll n,vector<vector<pr>> &adj,vector<ll> &delay){
    delay[src]=0;
    priority_queue<pr,vector<pr>,greater<pr>> pq;

    pq.push({0,src});

    while(!pq.empty()){
        ll u=pq.top().second;
        ll curr_delay=pq.top().first;
        pq.pop();

        if(curr_delay>delay[u]) continue;

        for(auto &edge: adj[u]){
            ll v=edge.first;
            ll weight=edge.second;
            if(curr_delay+weight<delay[v]){
                delay[v]=curr_delay+weight;
                pq.push({delay[v],v});
            }
        }
    }
}



int main(){
    fastio;
    ll n,m;
    cin>>n>>m;

    vector<vector<pr>> adj(n+1);
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    vector<ll> delay(n+1,INF);

    dijkstra(1,n,adj,delay);

    for(int i=1;i<=n;i++){
        cout<<delay[i]<<" ";
    }
}