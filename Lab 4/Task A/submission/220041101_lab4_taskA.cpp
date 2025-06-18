#include<iostream>
#include<limits>
#include<vector>
#include<queue>
using namespace std;

void dijkstra(int source, vector<vector<pair<int,int>>>&graph, vector<int> &dist )
{
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty())
    {
        int distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();


        for (auto &edge:graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u]+weight)
            {
                dist[v] = dist[u]+weight;
                pq.push({dist[v],v});
            }
        }

    }
}

int main()
{
    int n,m,u,v,i,w;
    cin>>n>>m;
    vector<vector<pair<int,int>>>graph(n+1);
    //int dist[n]={1000000000};
    vector<int> dist(n+1,100000);


    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    dijkstra(1,graph,dist);
    for(i=1;i<=n;i++)
        cout<<dist[i]<<" ";
}
