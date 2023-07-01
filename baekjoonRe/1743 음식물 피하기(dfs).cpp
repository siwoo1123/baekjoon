#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,k,tmp,ans;
bool v[105][105];
int dx[] = {0,0,-1,1},
    dy[] = {-1,1,0,0};

void dfs(int x, int y)
{
    v[x][y]=true;
    for(int i=0;i<4;i++)
    {
        if(v[x+dx[i]][y+dy[i]]==false)
        {
            tmp++;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) v[i][j]=true;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a][b]=false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==false){
                tmp=1;
                dfs(i,j);
                ans=max(ans,tmp);
            }
        }
    }
    cout<<ans;
    return 0;
}
