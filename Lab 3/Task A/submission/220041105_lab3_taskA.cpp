#include <bits/stdc++.h>
using namespace std;

using LL = long long;

vector<LL> money;
vector<vector<int>> adj;
vector<bool> visited;

LL totalMoney;
int totalPeople;

void dfs(int node)
{
    visited[node] = true;
    totalMoney += money[node];
    totalPeople++;

    for (int nei : adj[node])
    {
        if (!visited[nei])
            dfs(nei);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;

        money.assign(n, 0);
        adj.assign(n, vector<int>());
        visited.assign(n, false);

        LL totalSum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> money[i];
            totalSum += money[i];
        }

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;

        if (totalSum % n != 0)
        {
            possible = false;
        }
        else
        {
            LL target = totalSum / n;
            for (int i = 0; i < n; ++i)
            {
                if (!visited[i])
                {
                    totalMoney = 0;
                    totalPeople = 0;
                    dfs(i);
                    if (totalMoney % totalPeople != 0 || totalMoney / totalPeople != target)
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        cout << "Case " << i << ": " << (possible ? "Yes" : "No") << endl;
    }

}
