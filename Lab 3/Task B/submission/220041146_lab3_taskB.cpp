#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

vector<int> adj[MAX];
bool visited[MAX];

int dfs(int node)
{
    visited[node] = true;
    int count = 1;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            count += dfs(neighbor);
        }
    }
    return count;
}

int main()
{
    int n, p;
    cin >> n >> p;

    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> country_sizes;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int size = dfs(i);
            country_sizes.push_back(size);
        }
    }

    long long total_ways = (long long)n * (n - 1) / 2;
    long long same_country_ways = 0;

    for (int size : country_sizes)
    {
        same_country_ways += (long long)size * (size - 1) / 2;
    }

    cout << total_ways - same_country_ways << endl;

    return 0;
}