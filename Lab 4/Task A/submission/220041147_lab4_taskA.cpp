#include <bits/stdc++.h>
#include<vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
typedef pair<LL,LL>pr;

void djikstra(int src,int n,vector<vector<pr>>&adj,vector<LL>&dist){
    priority_queue<pr,vector<pr>,greater<pr>>pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        LL d=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(d>dist[v]){
            continue;
        }
        for(auto it:adj[v]){
            LL u=it.first;
            LL weight=it.second;
            if(dist[u]>dist[v]+weight){
                dist[u]=dist[v]+weight;
                pq.push({dist[u],u});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    fastio;
    int n,m;
    cin>>n>>m;
    vector<vector<pr>>adj(n+1);
    vector<LL>dist(n+1,LLONG_MAX);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int src=1;
    djikstra(src,n,adj,dist);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}