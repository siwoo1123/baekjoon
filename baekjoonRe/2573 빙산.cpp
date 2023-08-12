#include <iostream>
#include <algorithm>
using namespace std;

int n,m,map[305][305],dungiee=1,ans;
bool c[305][305], v[305][305];
int d[]={0,0,-1,1};

void dfs(int x, int y){
    v[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+d[i];
        int ny=y+d[3-i];
        if(map[nx][ny]>0&&!v[nx][ny]) dfs(nx,ny);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>map[i][j];
    }
    while (dungiee) {
        ans++;
        fill(&c[0][0], &c[n][m], false);
        fill(&v[0][0], &v[n][m], false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]==0) continue;
                c[i][j]=true;
                for(int k=0;k<4;k++)
                {
                    int nx=i+d[k];
                    int ny=j+d[3-k];
                    if(!c[nx][ny]&&map[nx][ny]==0&&map[i][j])map[i][j]--;
                }
            }
        }
        dungiee=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]&&!v[i][j]){
                    dungiee++;
                    dfs(i, j);
                }
            }
        }
        if(dungiee>=2) {cout<<ans; return 0;}
    }
    cout<<0;
    return 0;
}
