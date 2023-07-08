#include <iostream>
#include <algorithm>
using namespace std;

int n,house[1005][4],dp[1005][4],i;

int main()
{
    cin>>n;
    for(i=0;i<n;i++) cin>>house[i][0]>>house[i][1]>>house[i][2];
    dp[0][0]=house[0][0];
    dp[0][1]=house[0][1];
    dp[0][2]=house[0][2];
    for(i=1;i<n;i++)
    {
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+house[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+house[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+house[i][2];
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    return 0;
}
