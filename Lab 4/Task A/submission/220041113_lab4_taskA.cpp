#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {
public:
    ll size;
    vector<vector<pair<ll,ll>>> adjList;

public:
    Graph(ll n) : size(n), adjList(n+1){}
    void add_edge(ll u, ll v, ll wt){
        adjList[u].push_back(make_pair(v, wt));
        //adjList[v].push_back(make_pair(u, wt));
    }

};

void dijkstra(Graph &g, vector<ll> &dist, ll v){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto neighbor : g.adjList[u]){
                if(dist[neighbor.first] > d+neighbor.second){
                    dist[neighbor.first] = d+neighbor.second;
                    pq.push(make_pair(dist[neighbor.first], neighbor.first));
                }
        }
    }
}

int main(){
    ll n, m;
    cin>>n>>m;
    Graph G(n);
    while(m--){
        ll u,v ,wt;
        cin>>u>>v>>wt;
        G.add_edge(u, v, wt);
    }
    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;
    dijkstra(G, dist, n);
    for(int i=1; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<dist[n]<<endl;
    return 0;
}
