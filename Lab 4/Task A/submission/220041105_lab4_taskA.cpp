#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c,n,m,infinity=1e18;
    cin>>n>>m;

    vector<vector<pair<long long, long long>>> adj(n+1);
    vector<long long> dist(n+1,infinity);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dist[1]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
    pq.push({0,1});

    while(!pq.empty())
    {
        pair<long long,long long> crnt=pq.top();
        pq.pop();
        long long crnt_dist=crnt.first;
        long long crnt_node=crnt.second;
        if(crnt_dist>dist[crnt_node])
        {
            continue;
        }
        for(pair<long long,long long> neigh:adj[crnt_node])
        {
            long long nxt_node=neigh.first;
            long long edge_weight=neigh.second;
            if(dist[crnt_node]+edge_weight<dist[nxt_node])
            {
                dist[nxt_node]=dist[crnt_node]+edge_weight;
                pq.push({dist[nxt_node],nxt_node});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}
