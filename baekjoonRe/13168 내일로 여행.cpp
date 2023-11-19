#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef greater<int> gi;

map<string,int> trf;
int n,r,m,k1,arr1[105][105],arr2[105][105];
ll sum1,sum2;
// OOO1: 내일로 사용, OOO2: 내일로 미사용
string cities[205];

int getNo(string key)
{
    auto result = trf.find(key);
    return result->second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        fill(arr1[i],arr1[i]+n,INF);
        fill(arr2[i],arr2[i]+n,INF);
        arr1[i][i]=0;
        arr2[i][i]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        trf.insert({a,i});
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>cities[i];
    }
    cin>>k1;
    for(int i=0;i<k1;i++)
    {
        string t,s,d;
        int p;
        cin>>t>>s>>d>>p;
        p*=2;
        int sn=getNo(s),
            dn=getNo(d);
        arr2[sn][dn]=min(arr2[sn][dn],p);
        if(t=="S-Train"||t=="V-Train") arr1[sn][dn]=min(arr1[sn][dn],p/2);
        else if(t=="Mugunghwa"||t=="ITX-Saemaeul"||t=="ITX-Cheongchun") arr1[sn][dn]=min(arr1[sn][dn],0);
        else arr1[sn][dn]=min(arr1[sn][dn],p);
        
        arr2[dn][sn]=min(arr2[dn][sn],p);
        if(t=="S-Train"||t=="V-Train") arr1[dn][sn]=min(arr1[dn][sn],p/2);
        else if(t=="Mugunghwa"||t=="ITX-Saemaeul"||t=="ITX-Cheongchun") arr1[dn][sn]=min(arr1[dn][sn],0);
        else arr1[dn][sn]=min(arr1[dn][sn],p);
    }
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                arr1[i][j]=min(arr1[i][j],arr1[i][k]+arr1[k][j]);
                arr2[i][j]=min(arr2[i][j],arr2[i][k]+arr2[k][j]);
            }
    
    for(int i=1;i<m;i++)
    {
        int sn=getNo(cities[i-1]),
            dn=getNo(cities[i]);
        sum1+=arr1[sn][dn];
        sum2+=arr2[sn][dn];
    }
    sum1+=r*2;
    cout<<(sum1<sum2?"Yes":"No")<<'\n';
    return 0;
}
