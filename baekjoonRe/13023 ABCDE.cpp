#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
bool v[2004],flag;
vector<int> g[2004];

void dfs(int h,int tmp)
{
    v[h]=true;
    if(tmp>=5)
    {
        flag=true;
        return;
    }
    for(int x : g[h])
    {
        if(!v[x])
        {
            dfs(x,tmp+1);
        }
    }
    v[h]=false;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        fill(v,v+2004,false);
        dfs(i,1);
        if(flag)
        {
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
