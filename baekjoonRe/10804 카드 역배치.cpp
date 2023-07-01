#include <iostream>
#include <algorithm>
using namespace std;

int arr[25]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},i,a,b;

int main()
{
    for(i=0;i<10;i++)
    {
        cin>>a>>b;
        reverse(arr+a,arr+b+1);
    }
    for(i=1;i<=20;i++)cout<<arr[i]<<' ';
    return 0;
}

