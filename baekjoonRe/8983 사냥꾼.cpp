#include <iostream>
#include <algorithm>
using namespace std;

int n,m,l,sd[100005],x,y,ans,f,mid,e;

int main()
{
    cin>>n>>m>>l;
    for(int i=0;i<n;i++) cin>>sd[i];
    sort(sd,sd+n);
    for(int _=0;_<m;_++)
    {
        f=0;
        e=n-1;
        cin>>x>>y;
        while (f<=e) {
            mid=(f+e)/2;
            if(abs(sd[mid]-x)+y<=l)
            {
                ans++;
                break;
            }
            else if(sd[mid]>=x)
            {
                e=mid-1;
            }
            else
            {
                f=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
