/*
弗洛伊德算法
*/
#include<bits/stdc++.h>
using namespace std;

#define maxn 999999

int n,m,g[110][110],dis[110];
bool visit[110];

int Floyed(int src,int des)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    return g[src][des];
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
        ans=Floyed(1,n);
        cout<<ans<<endl;
    }

    return 0;
}
