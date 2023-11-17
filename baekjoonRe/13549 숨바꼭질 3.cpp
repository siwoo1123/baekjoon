#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,dp[400005];
vector<pii> v[400005];

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
    fill(dp,dp+200005, 2e9);
    
    cin>>n>>m;
    for(int i=0;i<max(n,m)*2;i++)
    {
        if(i-1>=0) v[i].push_back({i-1,1});
        v[i].push_back({i+1,1});
        v[i].push_back({i*2,0});
    }
    
    djikstra(n);
    cout<<dp[m];
    
    return 0;
}
