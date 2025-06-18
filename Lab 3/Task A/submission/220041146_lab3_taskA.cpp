#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

vector<int> adj[MAX];
bool visited[MAX];
int money[MAX];
vector<int> component;

void dfs(int node)
{
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            cin >> money[i];
            adj[i].clear();
            visited[i] = false;
        }

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;
        int total_sum = 0;

        for (int i = 1; i <= n; i++)
        {
            total_sum += money[i];
        }

        if (total_sum % n != 0)
        {
            possible = false;
        }
        else
        {
            int target = total_sum / n;
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    component.clear();
                    dfs(i);
                    int sum = 0;
                    for (int person : component)
                    {
                        sum += money[person];
                    }
                    if (sum % component.size() != 0 || (sum / component.size()) != target)
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        cout << "Case " << case_num << ": " << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}
