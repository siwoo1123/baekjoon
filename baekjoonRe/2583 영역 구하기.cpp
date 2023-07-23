#include <iostream>
#include <vector>
#include <algorithm>
#define nl '\n'
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int ans1,tmp,m,n,k;
bool v[105][105];
vi ans2;

void dfs(int x,int y)
{
    v[x][y]=true;
    tmp++;
    for(int i=0;i<4;i++)
    {
        pii nex={x+dx[i],y+dy[i]};
        if(nex.first>=0&&nex.second>=0&&nex.first<m&&nex.second<n&&!v[nex.first][nex.second])
        {
            dfs(nex.first, nex.second);
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int _=0;_<k;_++)
    {
        pii a,b;
        cin>>a.first>>a.second>>b.first>>b.second;
        for(int i=a.first;i<b.first;i++)
        {
            for(int j=a.second;j<b.second;j++)
            {
                v[i][j]=true;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!v[i][j])
            {
                tmp=0;
                ans1++;
                dfs(i, j);
                ans2.push_back(tmp);
            }
        }
    }
    sort(ans2.begin(),ans2.end());
    cout<<ans1<<nl;
    for(int x : ans2)
    {
        cout<<x<<' ';
    }
    return 0;
}
