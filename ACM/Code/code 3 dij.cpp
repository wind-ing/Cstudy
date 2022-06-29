/*
迪杰斯特拉算法
*/
#include<bits/stdc++.h>
using namespace std;

#define maxn 999999

int n,m,g[110][110],dis[110];
bool visit[110];

int Dijkstra(int src,int des)
{
    int temp,k;
    memset(visit,false,sizeof visit);
    for(int i=1;i<=n;i++)
    {
        dis[i]=(i==src?0:g[src][i]);
    }
    visit[src]=true;
    dis[src]=0;
    for(int i=1;i<=n;i++)
    {
        temp=maxn;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && temp>dis[j])
                temp=dis[k=j];
        }
        if(temp==maxn)
            break;
        visit[k]=true;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j]&&dis[j]>dis[k]+g[k][j])
                dis[j]=dis[k]+g[k][j];
        }
    }
    return dis[des];
}

int main()
{
    int ans;
    while(cin>>n>>m && (n+m))
    {
        memset(g,maxn,sizeof g);
        int a,b,c;
        while(m--)
        {
            cin>>a>>b>>c;
            if(c<g[a][b])
                g[a][b]=g[b][a]=c;
        }
        ans=Dijkstra(1,n);
        cout<<ans<<endl;
    }

    return 0;
}
