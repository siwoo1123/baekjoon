#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

string arr[20010];
int n,i;

int main() {
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n,cmp);
    for(i=0;i<n;i++)
    {
        if(i!=0&&arr[i-1]==arr[i])continue;
        cout<<arr[i]<<'\n';
    }
    return 0;
}
