#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> money;
vector<bool> visited;

void bfs(int start, int &sum, int &count) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    sum = money[start];
    count = 1;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                sum += money[neighbor];
                count++;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;

        adj.assign(n, vector<int>());
        money.resize(n);
        visited.assign(n, false);

        long long totalMoney = 0;
        for (int i = 0; i < n; i++) {
            cin >> money[i];
            totalMoney += money[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool possible = true;

        if (totalMoney % n != 0) {
            possible = false;
        } else {
            int target = totalMoney / n;

            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int sum = 0, count = 0;
                    bfs(i, sum, count);
                    if (sum % count != 0 || (sum / count) != target) {
                        possible = false;
                        break;
                    }
                }
            }
        }

        cout << "Case " << t << ": ";

        if(possible)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<< endl;
    }

}
