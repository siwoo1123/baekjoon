#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct St {
    int d,t,j,v,c;
} g,a[20];

int ans1=2147483647,n;
vector<int> ans2, whatweuse;

void dfs(int h, bool use, St s)
{
    if(h>=n)
    {
        if(g.d<=s.d&&g.t<=s.t&&g.j<=s.j&&g.v<=s.v&&ans1>s.c&&s.c!=0)
        {
            ans1=s.c;
            ans2=whatweuse;
        }
        else if(g.d<=s.d&&g.t<=s.t&&g.j<=s.j&&g.v<=s.v&&ans1==s.c&&whatweuse.size()<=ans2.size())
        {
            if(whatweuse<ans2)
            {
                ans1=s.c;
                ans2=whatweuse;
            }
        }
        return;
    }
    if(use)
    {
        s={s.d+a[h].d,s.t+a[h].t,s.j+a[h].j,s.v+a[h].v,s.c+a[h].c};
        whatweuse.push_back(h);
    }
    dfs(h+1,true,s);
    dfs(h+1,false,s);
    if(use)whatweuse.pop_back();
}

int main()
{
    cin>>n>>g.d>>g.t>>g.j>>g.v;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].d>>a[i].t>>a[i].j>>a[i].v>>a[i].c;
    }
    
    dfs(0,true,{0,0,0,0,0});
    dfs(0,false,{0,0,0,0,0});
    
    if(ans1==2147483647) ans1=-1;
    cout<<ans1<<'\n';
    for(int x : ans2) cout<<x+1<<' ';
    return 0;
}
