#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        component.push_back(curr);
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; ++case_num) {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);
        for (int i = 0; i < n; i++) {
            cin >> money[i];
        }

        vector<vector<int>> adjlist(n);
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--;
            v--;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<bool> visited(n, false);
        bool possible = true;
        int div=0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                bfs(i, adjlist, visited, component);

                int total = 0;
                for (int idx : component) {
                    total += money[idx];
                }
                if (total % component.size() != 0) {
                    possible = false;
                    break;
                }
            }
        }

        cout << "Case " << case_num << ": ";
        if(possible){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }

    return 0;
}

