#include <bits/stdc++.h>
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

priority_queue<int, vector<int>, greater<int>> heap;
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
                cout<<heap.top()<<'\n';
                heap.pop();
            }
        }
        else heap.push(c);
    }
    
    return 0;
}
