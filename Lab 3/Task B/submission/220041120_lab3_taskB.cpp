#include<bits/stdc++.h>
using namespace std;
int arr[100];

int bfs(int node, vector<vector<int>>graph)
{
    queue<int>q;
    int temp, comp=0;
    q.push(node);
    arr[node]=1;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        int sz=graph[temp].size();
        for(int i=0; i<sz; i++)
        {
            int next=graph[temp][i];
            if(!arr[next])
            {
                arr[next]=1;
                q.push(next);
                comp++;
            }

        }

    }
    return comp;

}

int main()
{
    int n,p,c1,c2,sum=0;
    int country=0;
    cin>>n>>p;
    vector<int>comp;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<p; i++)
    {
        cin>>c1>>c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    for(int i=0; i<n; i++)
    {
        if(!arr[i])
        {
            arr[i]=1;
            int c = bfs(arr[i],graph);
            comp.push_back(c+1);

            country++;
        }
    }
    for(int i=0; i<country; i++)
    {
        for(int j=i+1; j<country; j++)
        {

            sum+=comp[i]*comp[j];
        }
    }

    cout<<sum<< endl;

    return 0;
}
