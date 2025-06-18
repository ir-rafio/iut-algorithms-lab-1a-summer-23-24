#include <bits/stdc++.h>
using namespace std;
//argyroselene
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

vector<vector<int>>adj;
vector<int>money;
vector<bool>visited;

void bfs(int start,int& sum,int &count){
    queue<int>q;
    q.push(start);
    visited[start]=true;
    count=1;
    sum=money[start];
    while(!q.empty()){
        int node=q.front(); q.pop();
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
                sum+=money[neighbor];
                count++;
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        adj.assign(n, vector<int>());
        money.resize(n);
        visited.assign(n, false);
        long long total= 0;
        for (int i = 0; i < n; i++) {
            cin >> money[i];
            total+= money[i];
        }
        for (int i = 0; i < m; i++) {
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool possible = true;
        if (total% n != 0) {
            possible = false;
        } else {
            int target = total/ n;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int sum = 0, count = 0;
                    bfs(i,sum, count);
                    if (sum % count != 0 || (sum / count) != target) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        cout << "Case " << t << ": " << (possible ?"Yes" : "No") << endl;
    }
}
