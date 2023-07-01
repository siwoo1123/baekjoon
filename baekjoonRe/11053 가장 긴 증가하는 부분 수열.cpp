#include <iostream>
#include <algorithm>
using namespace std;

int n,a[1005],dp[1005],ans=1,i,j;

int main() {
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    fill(dp, dp+n, 1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
