#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,tmp,arr[10005],ans;
bool visited[10005];
vector<int> q[10005];

void dfs(int s)
{
    visited[s]=true;
    tmp++;
    for(int n : q[s])
    {
        if(visited[n]==false) dfs(n);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>b>>a;
        q[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        fill(visited, visited+n+1, false);
        dfs(i);
        arr[i]=tmp;
        tmp=0;
        ans=max(ans,arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==ans)cout<<i<<' ';
    }
}
