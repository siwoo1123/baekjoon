#include <bits/stdc++.h>
using namespace std;

int n,m,x,a,b,upres,dwres,u,v;
bool vs[100005];
vector<int> up[100005], down[100005];

void udfs(int s)
{
    vs[s]=true;
    for(int i:up[s])
    {
        if(!vs[i]){
            udfs(i);
            upres++;
        }
    }
}

void ddfs(int s)
{
    vs[s]=true;
    for(int i:down[s])
    {
        if(!vs[i]){
            ddfs(i);
            dwres++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>x;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        up[b].push_back(a);
        down[a].push_back(b);
    }
    
    udfs(x);
    vs[x]=false;
    ddfs(x);
    u=upres;
    v=n-(upres+dwres+1)+u;
    
    cout<<u+1<<' '<<v+1;
    
    return 0;
}

