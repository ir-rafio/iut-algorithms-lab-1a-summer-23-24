#include <iostream>
#include <vector>
#include <iostream>

#define nl "\n"
#define spc <<' '<<""
#define all(x) (x).begin() , (x).end()
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
typedef std::vector<ll> llvec;
using namespace std;



void dfs(ll node, const vector<vector<ll> >& graph, vector<bool>& visited, ll& count) {
    visited[node] = true;
    count++;

    for (ll neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

ll journeyToMoon(ll n, const vector<pair<ll, ll> >& astronautPairs) {
    vector<vector<ll> > graph(n);
    for (const auto& p : astronautPairs) {
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    vector<bool> visited(n, false);
    vector<ll> componentSizes;

    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            ll size = 0;
            dfs(i, graph, visited, size);
            componentSizes.push_back(size);
        }
    }

    long long totalPairs = (long long)n * (n - 1) / 2;
    long long sameCountryPairs = 0;

    for (ll size : componentSizes) {
        sameCountryPairs += (long long)size * (size - 1) / 2;
    }

    return totalPairs - sameCountryPairs;
}

int main() {
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll> > astronautPairs(p);

    for (ll i = 0; i < p; ++i) {
        cin >> astronautPairs[i].first >> astronautPairs[i].second;
    }

    cout << journeyToMoon(n, astronautPairs) << endl;

    return 0;
}