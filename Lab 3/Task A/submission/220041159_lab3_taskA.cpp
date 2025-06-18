#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}
bool canEqualize(int n, int m, const vector<int>& money, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<int> avg;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            long long sum = 0;
            int count = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                sum += money[curr];
                ++count;

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            if (sum % count != 0)
                return false;
            else
                avg.push_back(sum/count);
        }
    }
    for(int i=0;i<avg.size()-1;i++){
        if(avg[i]!=avg[i+1])
            return false;
    }
    return true;
}
void solve()
{
    int T;
    cin >> T;
    for (int j = 1; j <= T; ++j) {
        int n, m;
        cin >> n >> m;
        vector<int> money(n);
        for (int i = 0; i < n; ++i)
            cin >> money[i];

        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "Case " << j << ": ";
        if(canEqualize(n, m, money, adj)){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;

    }

}

signed main()
{
    pre();


        // cout << "Case " << tc << ": ";
        solve();

    return 0;
}
