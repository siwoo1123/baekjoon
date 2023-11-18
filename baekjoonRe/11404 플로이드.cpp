#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,m,arr[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        fill(arr[i],arr[i]+n+1,1e9);
        arr[i][i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=min(arr[a][b],c);
    }
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i][j]>=1e9) cout<<0<<' ';
            else cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
