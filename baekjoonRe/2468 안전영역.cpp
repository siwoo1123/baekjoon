#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m[105][105],ans=1,cnt,s=2147483647,b=-2147483647;
bool v[105][105];

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dfs(int a, int b)
{
    v[a][b]=true;
    for(int i=0;i<4;i++)
    {
        int na=a+dx[i],nb=b+dy[i];
        if(m[na][nb]&&!v[na][nb])
        {
            dfs(na,nb);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) {
        cin>>m[i][j];
        s=min(s,m[i][j]);
        b=max(b,m[i][j]);
    }
    for(int i=s;i<=b;i++)
    {
        memset(v, false, sizeof(v));
        cnt=0;
        for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(m[j][k]<=i)m[j][k]=0;
        for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)
            if(m[j][k]&&!v[j][k])
            {
                dfs(j,k);
                cnt++;
            }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
