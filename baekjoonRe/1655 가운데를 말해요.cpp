#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

priority_queue<int> pq1;
priority_queue<int, vi, gi> pq2;
int n, a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(i%2==1) pq1.push(a);
        else pq2.push(a);
        
        if(i>1&&pq1.top()>pq2.top())
        {
            int p1t=pq1.top(), p2t=pq2.top();
            pq1.pop();
            pq2.pop();
            pq1.push(p2t);
            pq2.push(p1t);
        }
        
        cout<<pq1.top()<<'\n';
    }
    
    return 0;
}
