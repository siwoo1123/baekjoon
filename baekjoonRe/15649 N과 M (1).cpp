#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int v[10] = {false, false, false, false, false, false, false, false, false, false};

void dfs(int h, int c, vector<int> o)
{
    if(c>=m)
    {
        for(int i=0;i<o.size();i++) cout<<o[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==false)
        {
            v[i]=true;
            o.push_back(i);
            dfs(i,c+1,o);
            o.pop_back();
            v[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    vector<int> o;
    dfs(1, 0, o);
    
    return 0;
}
