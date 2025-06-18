#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, int &temp_size, int &temp_sum, vector<bool> &visited, int ar[],vector<vector<int>> &adj) {
    visited[node] = true;
    temp_sum += ar[node];
    temp_size++;
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, temp_size, temp_sum, visited, ar, adj);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int test=1;test<=t;test++) {
        int n, m;
        cin >> n >> m;
        int ar[n];
        int total = 0;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            total += ar[i];
        }



        int avg = total / n;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (total % n != 0) {
            cout << "Case " << test<< ": No" << endl;
            continue;
        }

        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int temp_sum = 0, temp_size = 0;
                dfs(i, temp_size, temp_sum, visited, ar, adj);
                if (temp_sum/temp_size !=avg) {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) {
            cout << "Case " << test<< ": Yes" << endl;
        } else {
            cout << "Case " << test<< ": No" << endl;
        }
    }
    return 0;
}
