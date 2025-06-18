#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_NODES = 1010;

vector<int> adj[MAX_NODES];
bool visited[MAX_NODES];
long long coins[MAX_NODES];
long long totalAmount = 0;
int totalPeople = 0;

void dfs(int node) {
    visited[node] = true;
    totalAmount += coins[node];
    totalPeople++;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            visited[i] = false;
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            cin >> coins[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;
        int expectedAmountPerPerson = -1;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                totalAmount = 0;
                totalPeople = 0;
                dfs(i);

                if (totalAmount % totalPeople != 0) { //not integer
                    possible = false;
                    break;
                }

                int avg = totalAmount / totalPeople;
                if (expectedAmountPerPerson == -1) {
                    expectedAmountPerPerson = avg;
                } else if (avg != expectedAmountPerPerson) {
                    possible = false;
                    break;
                }
            }
        }

        cout << "Case " << caseNum << ": " << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}
