#include<iostream>
#include<queue>
#include<vector>

using namespace std;


int visited[100000]={0};
int n;
vector<vector<int>> graph(n);
int bfs(int src){
    queue<int> Q;
    int temp;
    Q.push(src);
    visited[src] =1;
    int size=0;
    while(!Q.empty()){
        temp=Q.front();
        Q.pop();
        size++;
        for(int i=0; i<n; i++){
            if(graph[temp][i] &&!visited[i]){
                Q.push(i);
                visited[i]=1;
            }
        }
    }
    return size;
}

int main(){
    int n, p;
    cin>>n>>p;

    for(int i=0; i<p; ++i){
        int a, b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    vector<int> countCountry;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            long long size=bfs(i);
            countCountry.push_back(size);
        }
    }

    long long totalPairs=(long long)n*(n-1)/2;
    long long sameCountry=0;

    for(int size:countCountry){
        sameCountry+=(long long)size*(size-1)/2;
    }

    long long res=totalPairs-sameCountry;
    cout<<res<<endl;

    return 0;
}
