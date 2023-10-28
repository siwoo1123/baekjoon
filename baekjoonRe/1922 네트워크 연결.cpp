#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int v,e,parent[1005],sum;
vector<pair<int, pair<int, int>>> edge;

int Find(int x)
{
  if(x==parent[x]) return x;
  return parent[x]=Find(parent[x]);
}

void Union(int x, int y)
{
  x=Find(x);
  y=Find(y);
  if(x>y) parent[x]=y;
  else parent[y]=x;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>v>>e;
    for(int i=0;i<=v;i++) parent[i]=i;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
   
    sort(edge.begin(),edge.end());
    for(int i=0;i<e;i++)
    {
        if(Find(edge[i].second.first) == Find(edge[i].second.second)) continue;
        Union(edge[i].second.first, edge[i].second.second);
        sum+=edge[i].first;
    }
   
    cout<<sum;

    
    return 0;
}
