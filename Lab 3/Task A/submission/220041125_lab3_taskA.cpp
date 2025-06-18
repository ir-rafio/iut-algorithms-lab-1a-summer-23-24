//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int total_money;
int total_people;

vector<vector<int>>adj_list(1000);
bool visited[1000];
int mon[1000];



void dfs1(int node) {
    visited[node] = true;
    total_money += mon[node];
    total_people++;

    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   
        int n,m;
        cin>>n>>m;
        //vector<int>arr;
        for(int i=0;i<=n;i++)
        {
            cin>>mon[i];
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        bool flag=true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                total_money = 0;
                total_people = 0;
                dfs1(i);

                if (total_money % total_people != 0) {
                flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"YES";
        }
        else
            cout<<"NO";
    }

    

    return 0;
}