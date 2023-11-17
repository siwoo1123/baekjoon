#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

priority_queue<ll, vector<ll>, greater<ll>> pq;
ll n, a=1;
bool hap[2000004];
//vector<bool> hap(2000004);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    hap[1]=true;
    for(ll i=2;i<2000003;i++)
    {
        if(!hap[i])
        {
            for(ll j=i*2;j<2000003;j+=i) hap[j]=true;
            pq.push(i);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        ll pt=pq.top();
        a*=pt;
        a%=2000003;
        
        pq.push(pt*pt);
        pq.pop();
//        cout<<pt<<endl;
    }
    cout<<a;
    
    return 0;
}
