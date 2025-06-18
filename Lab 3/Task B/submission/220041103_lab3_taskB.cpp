#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph, int& count)
{
    visited[node] = true;
    count++;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, graph, count);
        }
    }
}

int main()
{
    int n, p;
    cin >> n >> p;

    vector<vector<int>> graph(n);
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> countrySizes;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int count = 0;
            dfs(i, visited, graph, count);
            countrySizes.push_back(count);
        }
    }

    long long total = (long long)n * (n - 1) / 2;
    long long invalid = 0;
    for (int size : countrySizes)
    {
        invalid += (long long)size * (size - 1) / 2;
    }

    cout << total - invalid << endl;

}
