#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1005;

int money[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];
int groupCount, groupSum, targetAvg;

void dfs(int u) {
    visited[u] = true;
    groupCount++;
    groupSum += money[u];

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int cs = 1; cs <= T; ++cs) {
        int n, m;
        cin >> n >> m;

        int totalMoney = 0;
        for (int i = 0; i < n; ++i) {
            cin >> money[i];
            totalMoney += money[i];
            adj[i].clear(); 
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "Case " << cs << ": ";
        if (totalMoney % n != 0) {
            cout << "No\n";
            continue;
        }

        targetAvg = totalMoney / n;
        memset(visited, 0, sizeof(visited));
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                groupCount = groupSum = 0;
                dfs(i);
                if (groupSum != groupCount * targetAvg) {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible ? "Yes" : "No") << '\n';
    }

    return 0;
}
