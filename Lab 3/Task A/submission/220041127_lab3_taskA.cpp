#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}
void bfs(int start, vector<int>& money, vector<vector<int>>& adj, vector<bool>& visited, int& sum, int& count) {
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

void solve(int tc)
{
    int n,m;
    cin>>n>>m;
    vector<int> money(n);
    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){
        cin>>money[i];
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int total = 0;
    for(int i=0;i<n;i++){
        total += money[i];
    }
    bool flag = true;
    if (total % n != 0) {
        flag = false;
    } else {
        int target = total / n;

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int sum = 0;
                int count = 0;
                bfs(i, money, adj, visited, sum, count);

                if (sum != target * count) {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}