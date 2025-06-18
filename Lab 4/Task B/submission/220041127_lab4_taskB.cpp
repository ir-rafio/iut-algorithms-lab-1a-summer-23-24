#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const long long INF = 1e18;
typedef long long ll;
typedef pair<ll, ll> pr;

typedef tuple<ll, int, int> T; 

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pr>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<ll>> min_time(n + 1, vector<ll>(1001, INF));
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }

        priority_queue<T, vector<T>, greater<T>> pq;

        min_time[1][s[1]] = 0;
        pq.push({0, 1, s[1]});

        ll ans = INF;

        while (!pq.empty())
        {
            ll curr_time = get<0>(pq.top());
            int u = get<1>(pq.top());
            int speed = get<2>(pq.top());
            pq.pop();

            if (u == n)
            {
                ans = min(ans, curr_time);
                continue;
            }

            if (curr_time > min_time[u][speed])
                continue;

            
            int new_speed = s[u];
            if (curr_time < min_time[u][new_speed])
            {
                min_time[u][new_speed] = curr_time;
                pq.push({curr_time, u, new_speed});
            }

            for (auto &edge : adj[u])
            {
                int v = edge.first;
                ll w = edge.second;
                ll new_time = curr_time + w * speed;

                if (new_time < min_time[v][speed])
                {
                    min_time[v][speed] = new_time;
                    pq.push({new_time, v, speed});
                }
            }
        }

        cout << ans << "\n";
    }
}