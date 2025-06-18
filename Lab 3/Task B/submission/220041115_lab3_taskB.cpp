#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<bool> &visited,vector<vector<int>> &adj,int &count) {
    visited[node] = true;
    count++;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour,visited,adj,count);
        }
    }
}

int main() {
    long long n;
    int p,count;
    long long total;
    long long inval=0;
    cin>>n>>p;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    vector<int>c_size;
        for (int i = 0; i < p; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int count=0;
                dfs(i,visited,adj,count);
                c_size.push_back(count);
            }
        }
        total= n*(n-1)/2;
        for(int i=0;i<c_size.size();i++){
            inval+=c_size[i]*(c_size[i]-1)/2;

        }

        cout<<(total-inval);
    return 0;
}
