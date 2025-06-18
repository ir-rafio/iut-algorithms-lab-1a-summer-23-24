#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    int casenum = 1;
    while(T--){
        int n, m, total = 0;
        cin>>n>>m;
        vector<int> money(n);
        for (int i = 0; i<n; i++){
            cin>>money[i];
            total += money[i];
        }


        int avg = total/n;
        vector<vector<int>> adj(n);
        for(int i = 0; i<m; ++i){
            int u, v;
            cin>>u>>v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(total % n != 0){
            cout<<"Case "<<casenum<<": "<< "No"<<endl;
            casenum++;
            continue;
        }
        vector<bool> visited(n, false);
        bool possible = true;
        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int curr = q.front(); q.pop();
                    component.push_back(curr);
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                long long total_money = 0;
                for (int person : component)
                    total_money += money[person];
                if(total_money / component.size() != avg) {
                    possible = false;
                    break;
                }
            }
        }
        cout<<"Case "<<casenum<<": "<<(possible ? "Yes" : "No")<<endl;
        casenum++;
    }

    return 0;
}
