#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,x,dp[20005];
vector<pii> v[20005];

void djikstra(int s)
{
    priority_queue<pii,vector<pii>,greater<>> pq;
    pq.push({0,s});
    dp[s]=0;
    while(!pq.empty())
    {
        int cur=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        if(dis>dp[cur])continue;
        for(int i=0;i<v[cur].size();i++)
        {
            int nex=v[cur][i].first;
            int ndis=dis+v[cur][i].second;
            if(ndis<dp[nex])
            {
                dp[nex]=ndis;
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
    fill(dp,dp+20005,2e9);
    
    cin>>n>>m>>x;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    
    djikstra(x);
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==2e9) cout<<"INF\n";
        else cout<<dp[i]<<'\n';
    }
    
    return 0;
}
