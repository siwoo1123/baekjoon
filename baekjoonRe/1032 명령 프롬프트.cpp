#include <iostream>
#include <cstring>

using namespace std;

int n,len,i,j;
char arr[55][55];
bool flag;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    len=strlen(arr[0]);
    for(i=0;i<len;i++)
    {
        flag=true;
        for(j=0;j<n;j++)
        {
            if(arr[j][i]!=arr[0][i])
            {
                flag=false;
                break;
            }
        }
        if(flag) cout<<arr[0][i];
        else cout<<'?';
    }
    return 0;
}
