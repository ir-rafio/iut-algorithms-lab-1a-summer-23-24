#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const LL MAX= 1e18;


int main(){
    LL n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>adjl(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjl[a].push_back({b,c});
    }
    vector<LL>distance(n+1, MAX);
    distance[1]=0;
    priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<>>q;
    q.push({0,1});

    while(!q.empty()){
        LL delay= q.top().first;
        int node= q.top().second;
        q.pop();

        if(delay> distance[node])
            continue;
        for(auto &e: adjl[node]){
            int nextnode= e.first;
            int weight=e.second;

            if(distance[node]+weight<distance[nextnode]){
                distance[nextnode]=distance[node]+weight;
                q.push({distance[nextnode], nextnode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;
}
