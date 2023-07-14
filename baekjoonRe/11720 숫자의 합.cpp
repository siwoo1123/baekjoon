#include <iostream>
using namespace std;

int main()
{
    int n,sum=0;
    char m[105];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        sum+=m[i]-48;
    cout<<sum;
    return 0;
}
