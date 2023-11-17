#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,x,dp[1005][1005],ans;
vector<pii> v[1005];

void djikstra(int s)
{
    priority_queue<pii, vector<pii>, greater<>> pq;
    dp[s][s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int cur=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        if(dis>dp[s][cur]) continue;
        for(int i=0;i<v[cur].size();i++)
        {
            int nex=v[cur][i].first;
            int ndis=dis+v[cur][i].second;
            if(ndis<dp[s][nex])
            {
                dp[s][nex]=ndis;
                pq.push({ndis,nex});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>x;
    for(int i=0;i<=n;i++) fill(dp[i], dp[i]+n+1, 2e9);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    
    for(int i=1;i<=n;i++)
    {
        djikstra(i);
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][x]+dp[x][i]);
    }
    
    cout<<ans;
    
    return 0;
}
