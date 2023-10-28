#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int dp[100005],num[100005],ans,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    dp[0]=num[0];
    ans=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+num[i],num[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
