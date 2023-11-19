#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

ll n,e,v1,v2,dp[805][805],ans=INF;

int main()
{
    // Setting
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<805;i++)
    {
        fill(dp[i],dp[i]+805,INF);
        dp[i][i]=0;
    }
    
    // Input
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dp[a][b]=(dp[a][b]<c?dp[a][b]:c);
        dp[b][a]=(dp[b][a]<c?dp[b][a]:c);
    }
    cin>>v1>>v2;
    
    // Floyd Warshell
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    
    // Find Answer
    ans=min(ans,dp[1][v1]+dp[v1][v2]+dp[v2][n]);
    ans=min(ans,dp[1][v2]+dp[v2][v1]+dp[v1][n]);
    
    // Print Answer
    if(ans>=INF) cout<<-1;
    else cout<<ans;
    return 0;
}
