#include <iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long>dist(n+1,1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        long long d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>dist[u])
            continue;
        for(auto[v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }





}
