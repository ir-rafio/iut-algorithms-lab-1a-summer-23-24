#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


void bfs(int start, vector<vector<int>>&adjlist, vector<bool>&visited, vector<int>&money, int &s, int &c){
    queue<int>q;
    q.push(start);
    visited[start]=true;

    s=money[start];
    c=1;

    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(int nei: adjlist[n]){
            if(!visited[nei]){
                visited[nei]=true;
                q.push(nei);
                s+=money[nei];
                c++;
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;

        vector<vector<int>>adjl(n);
        vector<int>money(n);
        vector<bool>visited(n,false);

        int totalmoney=0;
        for(int i=0;i<n;i++){
            cin>>money[i];
            totalmoney+=money[i];
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        bool ispossible=true;

        if(totalmoney%n!=0){
            ispossible=false;
        }
        else{
            int p=totalmoney/n;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int s=0;
                    int c=0;
                    bfs(i,adjl,visited,money,s,c);
                    if(s%c!=0 || (s/c)!=p){
                        ispossible=false;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<i<<": "<<(ispossible ? "Yes":"No")<<endl;
    }
}
