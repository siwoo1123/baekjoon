#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

priority_queue<int> pq;
int a,b,c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        if(b==0)
        {
            if(pq.empty()) cout<<"-1\n";
            else
            {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else
        {
            for(int j=0;j<b;j++)
            {
                cin>>c;
                pq.push(c);
            }
        }
    }
    
    return 0;
}
