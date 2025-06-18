#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canDistributeEqually(int n, int m, vector<int>& money, vector<vector<int> >& adj) {
    vector<bool> visited(n, false);

    int lastMoney=0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            // BFS to find connected component
            queue<int> q;
            q.push(i);
            visited[i] = true;

            int people_count = 0;
            long long total_money = 0;
            // bool neib = false;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                total_money += money[u];
                people_count++;
                // if(adj[u].size() != 0) neib =true;
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            // Check if money can be equally distributed in this component
                // if(!neib) cout<<"person "<< i+1<<" had no neighbours, total money="<<total_money<<" last money= "<<lastMoney<<endl;
            if (total_money % people_count != 0)
                return false;
            if(i == 0) lastMoney = (total_money / people_count);
            else if( lastMoney != (total_money / people_count) ){
                return false;
            }
            //cout<<"this graph result, i was = "<<i+1<<" last money = "<<lastMoney<<" total money = "<<total_money<<endl;
            
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; ++case_num) {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> money[i];
            total += money[i];
        }

        // Check if total money is divisible by n, if so skip this case and take edges as dummy input
        if (total % n != 0) {
            cout << "Case " << case_num << ": No" << endl;
            
            for (int i = 0; i < m; ++i) {
                int u, v;
                cin >> u >> v;
            }
            continue;
        }

        //adjacency list
        vector<vector<int> > adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool result = canDistributeEqually(n, m, money, adj);
        cout << "Case " << case_num << ": " << (result ? "Yes" : "No") << endl;
    }

    return 0;
}