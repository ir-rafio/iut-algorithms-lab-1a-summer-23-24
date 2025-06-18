#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e18;

struct State
{
    ll time;
    int city;
    int speed;
    bool operator>(const State &other) const
    {
        return time > other.time;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> graph(n + 1);
        graph.clear();
        vector<int> s(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        for (int i = 1; i <= n; i++) cin >> s[i];
        vector<vector<ll>> min_time(n + 1, vector<ll>(1001, MAX));
        priority_queue<State, vector<State>, greater<State>> pq;

        min_time[1][s[1]] = 0;
        pq.push({0, 1, s[1]});

        while (!pq.empty())
        {
            State curr = pq.top();
            pq.pop();

            ll curr_time = curr.time;
            int u = curr.city;
            int curr_speed = curr.speed;

            if (curr_time > min_time[u][curr_speed]) continue;

            int new_speed = s[u];
            if (curr_time < min_time[u][new_speed])
            {
                min_time[u][new_speed] = curr_time;
                pq.push({curr_time, u, new_speed});
            }


            for (int i = 0; i <graph[u].size(); i++)
            {
                int v = graph[u][i].first;
                int w = graph[u][i].second;

                ll next_time = curr_time + 1LL * w * curr_speed;
                if (next_time < min_time[v][curr_speed])
                {
                    min_time[v][curr_speed] = next_time;
                    pq.push({next_time, v, curr_speed});
                }
            }
        }

        ll ans = MAX;
        for (int speed = 1; speed <= 1000; speed++)
        {
            ans = min(ans, min_time[n][speed]);
        }
        cout << ans << endl;
    }
}
