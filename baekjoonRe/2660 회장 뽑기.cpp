#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int score[55],visited[55],ans1=2147483647,n;
vector<int> g[55],ans2;

int bfs(int s)
{
    int sc=0;
    queue<int> q;
    q.push(s);
    visited[s]=0;
    while (!q.empty())
    {
        int h=q.front();
        q.pop();
        for(int i=0;i<g[h].size();i++)
        {
            if(visited[g[h][i]]==-1)
            {
                q.push(g[h][i]);
                visited[g[h][i]]=visited[h]+1;
                sc=max(sc,visited[g[h][i]]);
            }
        }
    }
    return sc;
}

int main()
{
    cin>>n;
    while(true)
    {
        int x,y;
        cin>>x>>y;
        if(x==-1&&y==-1) break;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        fill(visited, visited+n+1, -1);
        score[i]=bfs(i);
        ans1=min(ans1,score[i]);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(score[i]==ans1)
        {
            ans2.push_back(i);
        }
    }
    
    cout<<ans1<<' '<<ans2.size()<<endl;
    for(int x : ans2) cout<<x<<' ';
    return 0;
}
