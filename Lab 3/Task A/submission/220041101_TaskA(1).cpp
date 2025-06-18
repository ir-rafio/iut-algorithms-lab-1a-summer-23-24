#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int total_money=0;
int total_point=0;
int bfs(int node, int visited[], vector<int> vertices[],int money[])
{
    int sub_money=0;
    queue<int> Q;
    int temp;
    //int node=i;
    Q.push(node);
    visited[node]=1;
    total_point++;
    total_money+=money[node];
    sub_money += money[node];
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        int sz=vertices[temp].size();
        for(int k=0;k<sz;k++)
        {
            int nextnode=vertices[temp][k];
            if(!visited[nextnode])
            {
                visited[nextnode]=1;
                total_point++;
                total_money+=money[nextnode];
                sub_money+=money[nextnode];
                Q.push(nextnode);
            }
        }
    }
    return sub_money;
}


int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n,m,i,j,u,v;
    bool ans=true;
    //int total_money=0;

    cin>>n>>m;
    int money[n+1];
    vector<int> vertices[n+1];
    int visited[n+1]={0};

    for(i=1;i<=n;i++)
    {
        cin>>money[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        vertices[u].push_back(v);
        vertices[v].push_back(u);
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        int m1,m2;
        if(!visited[i])
        {
            if(cnt>1)
            {
               m1= bfs(i,visited,vertices,money);
               cnt++;
               //total_point=total_money-1;
               if(m1!=m2)
               {
                   ans=false;
                   break;
               }

            }
            else
            {
                m1=bfs(i,visited,vertices,money);
                m2=total_money;
                cnt++;
            }

        }
    }
    int temp;
    cout<<total_point;
    temp=total_money%total_point;
    if(ans && !temp)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    total_money=0;
    total_point=0;
    }

}
