#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1},
    dy[] = {0, 0, 1, -1, -1, -1, 1, 1},w,h,m[55][55],ans;
bool v[55][55];


void dfs(int a, int b)
{
    v[a][b]=true;
    for(int i=0;i<8;i++)
    {
        int na=a+dx[i],nb=b+dy[i];
        if(m[na][nb]>0&&!v[na][nb]&&na>=0&&nb>=0&&na<h&&nb<w)
        {
            dfs(na,nb);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        ans=0;
//        fill(&m[0][0],&m[54][54],0);
//        fill(&v[0][0],&v[54][54],0);
        memset(m, 0, sizeof(m));
        memset(v, 0, sizeof(v));
        cin>>w>>h;//h:높이, w:너비
        if(0==h&&w==0)break;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>m[i][j];
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(m[i][j]>0&&!v[i][j])
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
