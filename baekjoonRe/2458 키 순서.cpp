#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> down[505],up[505];
int n,m,ans,a,b;
bool v[505];

int godown(int start)
{
    int res=-1;
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        if(!v[now]){
            v[now]=true;
            res++;
            for(int x : down[now]) if(!v[x]) q.push(x);
        }
    }
    return res;
}

int goup(int start)
{
    int res=-1;
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        if(!v[now]){
            v[now]=true;
            res++;
            for(int x : up[now]) if(!v[x]) q.push(x);
        }
    }
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b; // a<b
        down[a].push_back(b);
        up[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        fill(v, v+505, false);
        int downres=godown(i);
        v[i]=false;
        int upres=goup(i);
        int tmp=downres+upres+1;
        if(tmp==n)ans++;
    }
    cout<<ans;
    return 0;
}
