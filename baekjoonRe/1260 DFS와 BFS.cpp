#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,v;
bool dv[1005],bv[1005];
vector<int> g[1005];

void dfs(int node)
{
    dv[node]=true;
    cout<<node<<' ';
    for(int i=0;i<g[node].size();i++)
    {
        int next=g[node][i];
        if(!dv[next]) dfs(next);
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    bv[node]=true;
    while(!q.empty())
    {
        int h=q.front();
        q.pop();
        cout<<h<<' ';
        for(int i=0;i<g[h].size();i++)
        {
            int next=g[h][i];
            if(!bv[next])
            {
                q.push(next);
                bv[next]=1;
            }
        }
    }
}

int main()
{
    cin>>n>>m>>v;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
    }
    dfs(v);
    cout<<endl;
    bfs(v);
    return 0;
}
