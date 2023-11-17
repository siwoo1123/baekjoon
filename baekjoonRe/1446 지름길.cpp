#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<> g;

int n,d,dp[10005];
vector<pii> road[10005]; // road[a]={b,c} => a,b:연결된 두 정점, c:가중치

void dij(int s) {
    priority_queue<pii, vector<pii>,g> pq; // {a,b}=>a:가중치,b:정점
    dp[s]=0;
    pq.push({0,s});
    
    while (!pq.empty()) {
        int cur=pq.top().second,
            dis=pq.top().first;
        pq.pop();
        if(dp[cur]<dis) continue;
        for(int i=0;i<road[cur].size();i++)
        {
            int nex=road[cur][i].first,
                ndis=road[cur][i].second+dis;
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
    
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        road[a].push_back({b,c});
    }
    for(int i=1;i<=d;i++)
    {
        road[i-1].push_back({i,1});
        dp[i]=IMAX;
    }
    
    dij(0);
    
    cout<<dp[d];
    
    return 0;
}
