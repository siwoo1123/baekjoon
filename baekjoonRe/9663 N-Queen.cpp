#include <iostream>
#include <algorithm>
using namespace std;

int n,arr[20],ans;
bool v[20];

void dfs(int y)
{
    if(y>n)
    {
        ans++;
        return;
    }
    for(int i=1;i<=n;i++) // y: 열, i: 행
    {
        if(v[i]==false)
        {
            bool flag=true;
            
            for(int j=1;j<y;j++) // j: 열, arr[j]: 행
            {
                if(abs(j-y)==abs(arr[j]-i)) flag=false;
            }
            
            if(flag)
            {
                v[i]=true;
                arr[y]=i;
                dfs(y+1);
                arr[y]=0;
                v[i]=false;
            }
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}
