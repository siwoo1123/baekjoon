#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

int n,arr[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(!arr[i][j]) arr[i][j]=1e9;
        }
    }
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]>=1e9) cout<<"0 ";
            else cout<<"1 ";
        }
        cout<<'\n';
    }
    
    return 0;
}
