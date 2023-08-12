#include <iostream>
using namespace std;

long long n, v[500005], i, ans=1, dp[500005];

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dp[n-1]=1;
    for(long long i=n-2;i>=0;i--){
        if(dp[i+1]+1<=v[i]){
            dp[i]=dp[i+1]+1;
        }
        else dp[i] = v[i];
        ans+=dp[i];
    }
    cout<<ans;
    return 0;
}
