#include<bits/stdc++.h>
using namespace std;

void bfs(int node, int visited[], vector<vector<int>> graph)
{
    queue<int> Q;
    int temp;
    Q.push(node);
    visited[node] = 1;
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        int siz = graph[temp].size();
        for(int i=0; i<siz; i++)
        {
            int next = graph[temp][i];
            if(!visited[next])
            {
                visited[next] = 1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    int t,n,m,u,v,sum = 0;

    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> n >> m;
        int ar[n],visited[n];
        vector<vector<int>> graph(n+1);
        for(int j=0; j<n; j++)
        {
            cin >> ar[j];
            sum += ar[j];
        }
        for(int j=0; j<m; j++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(sum%n != 0)
        {
            cout <<"Case"<<i<<":"<<"No"<<endl;
            break;
        }
        else

            cout<<"Case"<<i<<":"<<"Yes"<<endl;

        bfs(n,visited,graph);

    }
    return 0;
}

