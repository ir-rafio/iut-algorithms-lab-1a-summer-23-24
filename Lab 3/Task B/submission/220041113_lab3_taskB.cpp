#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, p;
    cin>>n>>p;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    for(int i = 0; i<p; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long totalnum = (n*(n-1)) / 2;
    vector<int> country_sizes;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int counter = 1;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                for (int neighbor : adj[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                        counter++;
                    }
                }
            }
            country_sizes.push_back(counter);
        }

    }
    long long totalinvalid = 0;
    int sum = 0;
    for(long long sizeT : country_sizes) {
        totalinvalid += (sizeT * (sizeT-1)) / 2;
        sum += sizeT;
    }
    long long ans = totalnum - totalinvalid;
    cout<<ans<<endl;

    return 0;
}
