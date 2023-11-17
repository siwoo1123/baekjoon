#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,x,d,dp[1005];
vector<pii> v[1005];

void djikstra(int s)
{
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0,s});
    dp[s]=0;
    
    while (!pq.empty()) {
        int cur=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        if(dp[cur]<dis) continue;
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
    fill(dp,dp+1005,IMAX);
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    
    cin>>x>>d;
    djikstra(x);
    cout<<dp[d];
    
    return 0;
}
