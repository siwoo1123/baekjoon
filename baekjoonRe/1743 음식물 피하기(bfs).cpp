#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int n,m,k,ans;
bool v[105][105];
int dx[] = {0,0,-1,1},
    dy[] = {-1,1,0,0};

int bfs(int x, int y)
{
    int tmp=1;
    queue<pii> q;
    q.push({x,y});
    v[x][y]=true;
    while (!q.empty()) {
        pii now = q.front();
        
        q.pop();
        for(int i=0;i<4;i++)
        {
            pii next={now.first+dx[i],now.second+dy[i]};
            if(!v[next.first][next.second])
            {
                v[next.first][next.second]=true;
                q.push(next);
                tmp++;
            }
        }
    }
    return tmp;
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
                ans=max(ans,bfs(i,j));
            }
        }
    }
    cout<<ans;
    return 0;
}
