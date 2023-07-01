#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,a,b,visited[105];
vector<int> g[105];

bool nv(int p)
{
    return visited[p]==-1;
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=0;
    while (!q.empty()) {
        int h=q.front();
        q.pop();
        for(int i=0;i<g[h].size();i++)
        {
            int next=g[h][i];
            if(nv(next))
            {
                q.push(next);
                visited[next]=visited[h]+1;
            }
        }
    }
}

int main()
{
    fill(visited, visited+105, -1);
    cin>>n>>a>>b>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(a);
    cout<<visited[b];
    return 0;
}
