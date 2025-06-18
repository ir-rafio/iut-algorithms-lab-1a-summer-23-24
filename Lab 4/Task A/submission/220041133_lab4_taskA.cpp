#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define spc <<' '<<""
#define all(x) (x).begin() , (x).end()
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
typedef vector<ll> llvec;

typedef priority_queue<
            pair<ll, ll>,
            vector<pair<ll, ll>>,
            greater<pair<ll, ll>> // Min-heap for pairs (distance, vertex)
        > min_heap_concise;


class myGraph {
private:
    vector<vector<pair<ll, ll>>> adjList;
    ll numVertices;

public:
    myGraph(ll n) : numVertices(n) {
        adjList.resize(n);
    }

    void addEdge(ll u, ll v, ll w) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjList[u].push_back({v, w});
        } else {
            cerr << "Error: Invalid vertex index for adding edge ("
                      << u+1 << " -> " << v+1 << ")." << endl;
        }
    }

    void printGraph() const {
        cout << "Graph Adjacency List (Directed Weighted):" << endl;
        for (ll i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ":";
            for (const auto& edge : adjList[i]) {
                cout << " -> (" << edge.first << ", weight " << edge.second << ")";
            }
            cout << endl;
        }
    }

    // void simplePrint(){

    // }

    const vector<pair<ll, ll>>& getNeighbors(ll u) const {
        if (u >= 0 && u < numVertices) {
            return adjList[u];
        }
        static const vector<pair<ll, ll>> emptyVec;
        return emptyVec;
    }

    ll getNumVertices() const {
        return numVertices;
    }
};


vector<ll> dijkstra(const myGraph& g, ll src) {
    ll n = g.getNumVertices();
    vector<ll> dist(n, LONG_MAX);
    vector<bool> visited(n, false);

    min_heap_concise pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& [v, weight] : g.getNeighbors(u)) {
            if (!visited[v] && currDist + weight < dist[v]) {
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}



int main()
{
    fastread();

    ll n,m;
    cin>>n>>m;
    myGraph gr(n);

    for (size_t i = 0; i < m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        gr.addEdge(--a,--b,c);
    }
    
    vector<ll> shortest = dijkstra(gr, 0);

    for (auto &&i : shortest)
    {
        cout<<i<<" ";
    }
    

    return 0;
}