#include <iostream>
using namespace std;

int t, l, r, i, j, k, dp[36][36];

int main()
{
    cin>>t;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[2][0]=1;
    dp[2][1]=2;
    dp[2][2]=1;
    
    for(j=3;j<=35;j++)
    {
        for(k=0;k<=j;k++)
        {
            dp[j][k]=dp[j-1][k-1]+dp[j-1][k];
        }
    }
    
    for(i=0;i<t;i++)
    {
        cin>>l>>r;
        cout<<dp[r][l]<<endl;
    }
    return 0;
}
