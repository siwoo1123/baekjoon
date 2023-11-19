#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,k,x,dp[300005];
vector<pii> v[300005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dp,dp+300005,INF);
    
    cin>>n>>m>>k>>x;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back({b,1});
    }
    
    priority_queue<pii,vector<pii>,greater<>> pq;
    pq.push({0,x});
    dp[x]=0;
    while(!pq.empty())
    {
        int cur=pq.top().second,
            dis=pq.top().first;
        pq.pop();
        if(dis>dp[cur])continue;
        for(int i=0;i<v[cur].size();i++)
        {
            int nex=v[cur][i].first,
                ndis=dis+v[cur][i].second;
            if(ndis<dp[nex])
            {
                dp[nex]=ndis;
                pq.push({ndis,nex});
            }
        }
    }
    
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==k)
        {
            flag=false;
            cout<<i<<'\n';
        }
    }
    if(flag)cout<<"-1";
    return 0;
}
