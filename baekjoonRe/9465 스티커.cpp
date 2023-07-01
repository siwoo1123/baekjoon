#include <iostream>
#include <algorithm>
using namespace std;

int t,n,arr[4][100002],dp[4][100002],ans;

int main()
{
    cin>>t;
    for(int _=0;_<t;_++)
    {
        cin>>n;
        for(int i=1;i<=2;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>arr[i][j];
            }
        }
        dp[1][1]=arr[1][1];
        dp[2][1]=arr[2][1];
        ans=max(dp[1][1],dp[2][1]);
        for(int i=2;i<=n;i++)
        {
            dp[1][i]=max(dp[2][i-1],dp[2][i-2])+arr[1][i];
            dp[2][i]=max(dp[1][i-1],dp[1][i-2])+arr[2][i];
            ans=max({ans,dp[1][i],dp[2][i]});
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
