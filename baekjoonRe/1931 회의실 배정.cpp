#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[100005];
// f: 끝나는 시각, s: 시작 시각
int n, ans, le;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int c,b;
        cin>>c>>b;
        a[i]={b,c};
    }
    
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i].second>=le)
        {
            le=a[i].first;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
