#include <iostream>
#include <algorithm>
using namespace std;

int visited[55][55],t,m,n,k,ans;
int dh[4]={0,0,-1,1},
    dy[4]={-1,1,0,0};

void revisited()
{
    for(int i=0;i<55;i++)
    {
        for(int j=0;j<55;j++)
        {
            visited[i][j]=1;
        }
    }
}

void dfs(int h, int y)
{
//    cout<<h<<" "<<y<<"\n";
    visited[h][y]=1;
    for(int i=0;i<4;i++)
    {
        int nh=h+dh[i], ny=y+dy[i];
        if(0<=nh&&nh<n&&0<=ny&&ny<m)
        {
            if(visited[nh][ny]==0) dfs(nh,ny);
        }
    }
}

int main()
{
    cin>>t;
    for(int _=0;_<t;_++)
    {
        revisited();
        ans=0;
        cin>>m>>n>>k;
        for(int i=0;i<k;i++)
        {
            int y,h;
            cin>>y>>h;
            visited[h][y]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
//                cout<<i<<" "<<j<<"\n";
                if(visited[i][j]==0)
                {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
