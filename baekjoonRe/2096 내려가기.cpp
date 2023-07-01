#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][3],n,dp2[2][3];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dp[1][0]=max(dp[0][0],dp[0][1])+a;
        dp[1][1]=max({dp[0][0],dp[0][1],dp[0][2]})+b;
        dp[1][2]=max(dp[0][1],dp[0][2])+c;
        dp[0][0]=dp[1][0];
        dp[0][1]=dp[1][1];
        dp[0][2]=dp[1][2];
        
        dp2[1][0]=min(dp2[0][0],dp2[0][1])+a;
        dp2[1][1]=min({dp2[0][0],dp2[0][1],dp2[0][2]})+b;
        dp2[1][2]=min(dp2[0][1],dp2[0][2])+c;
        dp2[0][0]=dp2[1][0];
        dp2[0][1]=dp2[1][1];
        dp2[0][2]=dp2[1][2];
    }
    cout<<max({dp[0][0],dp[0][1],dp[0][2]})<<' '<<min({dp2[0][0],dp2[0][1],dp2[0][2]})<<' ';
    return 0;
}
