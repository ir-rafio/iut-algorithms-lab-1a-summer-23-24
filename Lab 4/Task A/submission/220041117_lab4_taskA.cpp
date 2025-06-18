#include<iostream>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

const long long INF = 1e18;

void dijkstra (int n, vector<vector<pair<int, int>>> &graph, int start){
    vector<long long> distance (n+1, INF);
    distance[start]=0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int current_c = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(current_c > distance[node]){
            continue;
        }
        for(auto edge: graph[node]){
            int neighbour = edge.first;
            int edge_c = edge.second;
            if(distance[node]+edge_c < distance[neighbour]){
                distance[neighbour] = distance[node]+edge_c;
                pq.push({distance[neighbour], neighbour});
            }
        }
    }
    for(int i=1; i<=n; ++i){
        cout << distance[i] << " ";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0; i<m; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    dijkstra (n, graph, 1);
}
