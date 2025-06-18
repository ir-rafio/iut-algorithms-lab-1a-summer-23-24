#include<bits/stdc++.h>
using namespace std;

int arr[100];
vector<vector<pair<int,int>>>graph[1000];


void Dj(int n, int s)
{
    for(int i=0; i<n; i++)
    {
        arr[i]=999;
        arr[s]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>>q;

        q.push({0,s});

        while(!q.empty())
        {
            pair<int,int>u=q.top();
            q.pop();


            for(auto e:graph[u.first])
            {
                if(arr[e.first] > arr[u.first] + e.second)
                {
                    arr[e.first] = arr[u.first] + e.second;

                    q.push({arr[e.first]}, e.first);
                }

            }
        }

    }
}

int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n,m,a,b,c;
        cin>>n>>m;
        while(m--)
        {
            cin>>a>>b>>c;
            graph[a-1].push{b-1,c});

        }
        Dj(n,0);
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        return 0;

    }







