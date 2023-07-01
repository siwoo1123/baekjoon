#include <iostream>
#include <algorithm>
using namespace std;

int n,m,v[505][505],cnt,wide,tmp;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dfs(int x, int y)
{
    tmp++; 
    v[x][y]=0;
    for(int i=0;i<4;i++)
    {
        if(v[x+dx[i]][y+dy[i]]==1)
        {
            dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==1)
            {
                cnt++;
                tmp=0;
                dfs(i,j);
                wide=max(wide,tmp);
            }
        }
    }
    cout<<cnt<<endl<<wide;
    return 0;
}
