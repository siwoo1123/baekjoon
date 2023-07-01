#include <iostream>
#include <vector>
using namespace std;

int n,m,ans;
bool visited[1005];
vector<int> v[1005];

void dfs(int p)
{
    visited[p]=true;
    for(int i=0;i<v[p].size();i++)
    {
        if(!visited[v[p][i]])
        {
            dfs(v[p][i]);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
