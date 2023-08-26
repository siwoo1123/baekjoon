#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ans, g[110];
bool v[110], cycle;
int n;

void dfs(int i, int start)
{
    v[i]=true;
    for(int x : g[i])
    {
        if(!v[x]) dfs(x,start);
        else if(x==start) cycle = true;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int ipt;
        cin>>ipt;
        g[i].push_back(ipt);
    }
    for(int i=1;i<=n;i++)
    {
        fill(v,v+110,false);
        cycle=false;
        dfs(i,i);
        if(cycle){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(int x : ans) cout<<x<<'\n';
    return 0;
}
