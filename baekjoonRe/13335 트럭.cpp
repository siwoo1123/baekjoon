#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,w,l,a,t,sum,whoin;
bool last;
queue<int> bridge;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>w>>l;
    for(int i=0;i<w;i++) bridge.push(0);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        while(sum+a-bridge.front()>l)
        {
            sum-=bridge.front();
            bridge.pop();
            bridge.push(0);
            t++;
        }
        sum-=bridge.front();
        bridge.pop();
        bridge.push(a);
        sum+=a;
        t++;
    }
    t+=w;
    cout<<t;
    
    return 0;
}

