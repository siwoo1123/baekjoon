#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int ans,n,m,arr[505][505];
bool v[505][505];

int d[]={0,0,-1,1};

void dfs(int step, int sum, int x, int y)
{
    if(step>=4)
    {
        ans=max(sum,ans);
        return;
    }
    if(x<0||y<0||x>=n||y>=m||v[x][y]) return;
    v[x][y]=true;
    for(int i=0;i<4;i++)
    {
        dfs(step+1,sum+arr[x][y],x+d[i],y+d[3-i]);
    }
    v[x][y]=false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dfs(0,0,i,j);
        }
    }
    
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m;j++)
        {
            int sum=arr[i][j]+arr[i][j-1]+arr[i-1][j]+arr[i+1][j];
            ans=max(ans,sum);
        }
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int sum=arr[i][j]+arr[i][j+1]+arr[i-1][j]+arr[i+1][j];
            ans=max(ans,sum);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            int sum=arr[i][j]+arr[i+1][j]+arr[i][j-1]+arr[i][j+1];
            ans=max(ans,sum);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            int sum=arr[i][j]+arr[i-1][j]+arr[i][j-1]+arr[i][j+1];
            ans=max(ans,sum);
        }
    }
    cout<<ans;
    
    return 0;
}
