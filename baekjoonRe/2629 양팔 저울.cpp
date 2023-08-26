#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool lists[40005], thisturn[40700];
int n,m,ipt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int _=0;_<n;_++)
    {
        fill(thisturn, thisturn+40700, false);
        cin>>ipt;
        for(int i=40000;i>=1;i--)
        {
            if(lists[i])
            {
                thisturn[i+ipt]=true;
                thisturn[abs(i-ipt)]=true;
            }
        }
        lists[ipt]=true;
        for(int i=1;i<=40000;i++)if(thisturn[i]==true)lists[i]=true;
//        for(int i=1;i<=10;i++) cout<<lists[i]<<' ';
//        cout<<endl;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>ipt;
        if(lists[ipt]) cout<<"Y ";
        else cout<<"N ";
    }
    cout<<endl;
    
    
    return 0;
}
