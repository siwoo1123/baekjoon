#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos {
    int h,y;
};

int h,y,visited[55][55],ans;
char arr[55][55];
int dh[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void rv()
{
    for(int i=0;i<55;i++)
    {
        for(int j=0;j<55;j++)
        {
            visited[i][j]=-1;
        }
    }
}

void bfs(Pos s)
{
    queue<Pos> q;
    q.push(s);
    visited[s.h][s.y]=0;
    while (!q.empty()) {
        Pos t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            Pos n={t.h+dh[i],t.y+dy[i]};
            if(n.h>=0&&n.y>=0&&n.h<h&&n.y<y&&arr[n.h][n.y]=='L'&&visited[n.h][n.y]==-1)
            {
                q.push(n);
                visited[n.h][n.y]=visited[t.h][t.y]+1;
                ans=max(ans,visited[n.h][n.y]);
            }
        }
    }
}

int main()
{
    cin>>h>>y;
    for(int i=0;i<h;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(arr[i][j]=='L')
            {
                rv();
                bfs({i,j});
            }
        }
    }
    cout<<ans;
    return 0;
}
