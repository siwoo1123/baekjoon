#include <iostream>
using namespace std;

int n, ans=1, a[300005], i;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        if(a[i-1]%2!=a[i]%2) ans++;
    }
    cout<<ans;
    return 0;
}
