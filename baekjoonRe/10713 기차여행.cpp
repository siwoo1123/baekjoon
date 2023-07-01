#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, ans, route[100005], place[100005], i, j;
struct {long long a, b, c;} cost[100005];

int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++) cin>>place[i];
    for(i=1;i<=n-1;i++) cin>>cost[i].a>>cost[i].b>>cost[i].c;
    
    for(i=1;i<m;i++)
    {
        long long a=min(place[i-1], place[i]), b=max(place[i-1], place[i]);
        route[a]+=1;
        route[b]-=1;
    }
    int w=0;
    for(i=0;i<n;i++)
    {
        w += route[i];
        ans+=min(cost[i].c+cost[i].b*w,cost[i].a*w);
    }
    cout<<ans;
    return 0;
}
