#include<iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;
int n, m;
long long dist[100000];

struct Edge
{
    int to;
    long long delay;
};
vector<Edge> adj[100000];

void dijkstra()
{
    int src=1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for(int i=0; i<=n; i++)
    {
        dist[i]=INF;
    }
    dist[src]=0;
    pq.push({0, src});
    while (!pq.empty())
    {
        long long currDelay = pq.top().first;
        int node = pq.top().second; //to extract node w smallest current delay
        pq.pop();
        for (Edge e:adj[node])
        {
            int nextNode = e.to;
            long long edgeDelay = e.delay;
            if (dist[nextNode] > dist[node] + edgeDelay)
            {
                dist[nextNode] = dist[node] + edgeDelay;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

    int main(){
        int a, b, c;
        cin>> n>>m;

        for(int i=0; i<m; i++)
        {
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }
        dijkstra();

        for(int i=1; i<=n; i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;

        return 0;
    }
