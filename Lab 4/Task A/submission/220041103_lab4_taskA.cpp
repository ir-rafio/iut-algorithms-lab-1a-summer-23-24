#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
void dijkstra(int source, int n, vector<vector<pair<long long, long long>>>& graph, vector<long long>& d){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    d[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        long long dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > d[u]) continue;

        for (auto edge : graph[u]) {
            long long v = edge.first;
            long long w = edge.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }

}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> graph(n + 1);
    vector<long long> d(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    dijkstra(1, n, graph, d);

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}
