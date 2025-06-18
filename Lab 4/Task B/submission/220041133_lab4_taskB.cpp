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
    vector<int> bikes;
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
                      << u << " -> " << v << ")." << endl;
        }
    }

    void addBiDirecEdge(ll u, ll v, ll w) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjList[u].push_back({v, w});
            adjList[v].push_back({u,w});
        } else {
            cerr << "Error: Invalid vertex index for adding edge ("
                      << u << " -> " << v << ")." << endl;
        }
    }

    void addBikes(ll bk){
        bikes.push_back(bk);
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

    int getBike(int n){
        return bikes[n];
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

// Dijkstra using myGraph
vector<ll> dijkstraBikes( myGraph& g, ll src) {
    ll n = g.getNumVertices();
    vector<ll> dist(n, LONG_MAX);
    vector<int> visited(n, 2);
    int currBike=INT_MAX;

    min_heap_concise pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (visited[u]<=0) continue;
        visited[u]--;
        cout<<"current bike value= "<<currBike <<"bike of "<<u<<" = "<<g.getBike(u)<<nl;
        
        currBike = ( currBike > g.getBike(u) ? g.getBike(u) : currBike);

        for (const auto& [v, weight] : g.getNeighbors(u)) {
            if (  visited[v]>0 ) {
                if(  currDist + ( weight * currBike)   < dist[v] )
                    dist[v] = currDist + ( weight * currBike) ;
                pq.push({dist[v], v});
                visited[v]--;
            }
        }
    }

    return dist;
}



int main()
{
    fastread();

    int t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        myGraph gr(n);

        for (size_t i = 0; i < m; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            gr.addBiDirecEdge(--a,--b,c);
        }

        for (size_t i = 0; i < n; i++)
        {
            cin>>m;
            gr.addBikes(m);
        }
        
        
        vector<ll> shortest = dijkstraBikes(gr, 0);

        for (auto &&i : shortest)
        {
            cout<<i<<" ";
        }
    }
    
    

    return 0;
}