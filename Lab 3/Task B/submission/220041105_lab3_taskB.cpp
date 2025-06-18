#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node, int& count)
{
    visited[node] = true;
    count++;
    for (int nei : adj[node])
    {
        if (!visited[nei])
            dfs(nei, count);
    }
}

int main()
{
    long long n;
    int p;
    cin >> n >> p;

    adj.resize(n);
    visited.resize(n);

    for (int i = 0; i < p; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> country_sizes;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            int count = 0;
            dfs(i, count);
            country_sizes.push_back(count);
        }
    }

    long long total = n * (n - 1) / 2;
    long long same = 0;

    for (long long size : country_sizes)
        same += size * (size - 1) / 2;

    cout << total - same << endl;
}
