#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

priority_queue<pii, vector<pii>, greater<pii>> heap;
int x,c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>c;
        if(c==0) {
            if(heap.empty()) cout<<0<<'\n';
            else
            {
                pii top = heap.top();
                if(top.second==-1) cout<<top.first*(-1)<<'\n';
                else cout<<top.first<<'\n';
                heap.pop();
            }
        }
//        else heap.push(c);
        else
        {
            if(c<0) heap.push({c*(-1), -1});
            else heap.push({c,1});
        }
    }
    
    return 0;
}
