#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[130][130], ans0, ans1, i, j;

void cp(pair<int,int> sp, int l)
{
    int a = arr[sp.first][sp.second];
    bool flag = false;
    for(i = sp.first; i <= sp.first+l-1; i++)
    {
        for(j = sp.second; j <= sp.second+l-1; j++)
        {
            if(arr[i][j] != a)
            {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag)
    {
        if(a==0) ans0++;
        else ans1++;
        return;
    }
    cp(sp, l/2);
    cp({sp.first, sp.second+(l/2)}, l/2);
    cp({sp.first+(l/2), sp.second}, l/2);
    cp({sp.first+(l/2), sp.second+(l/2)}, l/2);
}

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cp({0,0},n);
    cout<<ans0<<endl<<ans1;
    return 0;
}
