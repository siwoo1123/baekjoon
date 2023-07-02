#include <iostream>
#include <algorithm>

using namespace std;

int out[2005][2005],sav,i,j,k,l,ans,n,m;
char ga[2005][2005];

int ctoi(char a)
{
    return a-'0';
}

int main()
{
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        cin>>ga[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            sav=max({
                out[j-1][i-1],
                out[j][i-1],
                out[j+1][i-1]
            });
            out[j][i]=sav+ctoi(ga[j-1][i-1]);
            ans=max(ans,sav);
        }
    }
    cout<<ans;
    return 0;
}
