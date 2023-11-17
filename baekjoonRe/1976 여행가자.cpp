#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,a;
vi plan;
int parent[205];

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
    
    cin>>n>>m;
    for(int i=0;i<=n;i++) parent[i]=i;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            if(a) Union(i, j);
        }
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>a;
        plan.push_back(a);
    }
    for(int i=1;i<m;i++)
    {
        if(Find(plan[i-1])!=Find(plan[i]))
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
