#include <iostream>
#include <algorithm>
using namespace std;

int ans,chu[20],k,s;
bool v[2600005];
void dfs(int h, int w, int sum)
{
    if(h>=k)
    {
        if(sum>=0)v[sum]=true;
        return;
    }
    if(w==1) sum+=chu[h];
    else if(w==2) sum-=chu[h];
    dfs(h+1,1,sum);
    dfs(h+1,2,sum);
    dfs(h+1,3,sum);
}

int main()
{
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>chu[i];
        s+=chu[i];
    }
    dfs(0,1,0);
    dfs(0,2,0);
    dfs(0,3,0);
    for(int i=1;i<=s;i++)
    {
        if(!v[i]) ans++;
    }
    cout<<ans;
    return 0;
}
