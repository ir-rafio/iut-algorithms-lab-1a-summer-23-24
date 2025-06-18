#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long int ll;

vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V)
{
    vector<vector<vector<int>>> adj(V+1); // adj[u] = list of {v, weight}
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        //adj[v].push_back({u,wt}); // for bidirected
    }
    return adj;
}

vector<long long> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    vector<vector<vector<int>>> adj = constructAdj(edges, V+1);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq; //min heap 
    vector<long long> dist(V+1, LLONG_MAX); // distances initialized to "infinity"

    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty())
    {
        int u = pq.top()[1]; //taking the node (second element)
        int currentDistance = pq.top()[0];
        pq.pop();

        if (currentDistance > dist[u]) continue;

        

        for (auto &x : adj[u])
        {
            int v = x[0];
            int weight = x[1];

            if ( dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<long long> dist = dijkstra(n, edges, 1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}