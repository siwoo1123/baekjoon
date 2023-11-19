#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

long long n,m,cnt,mod[1005],sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    mod[0]++;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        sum+=a;
        sum%=m;
        mod[sum]++;
    }
    for(int i=0;i<m;i++)
    {
        long long cm=mod[i];
        cnt+=(cm*(cm-1))/2;
    }
    
    cout<<cnt;
    
    return 0;
}
