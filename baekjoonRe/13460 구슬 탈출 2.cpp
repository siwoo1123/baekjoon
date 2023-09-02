#include <bits/stdc++.h>
#define x first
#define y second
#define IMAX 2147483647
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,m,ans=IMAX;
char gm[15][15];
int d[]={-1,1,0,0};

void bfs(pii rs, pii bs)
{
    queue<pii> rq, bq;
    queue<int> sq;
    rq.push(rs);
    bq.push(bs);
    sq.push(1);
    while (sq.front()<=10)
    {
        pii r=rq.front(), b=bq.front();
        int step=sq.front();
        rq.pop();
        bq.pop();
        sq.pop();
        
        for(int i=0;i<4;i++)
        {
            pii nr=r, nb=b;
            bool rf=false, bf=false;
            // red part
            while(1)
            {
                nr.x+=d[i];
                nr.y+=d[3-i];
                if(gm[nr.x][nr.y]=='O') rf=true;
                else if(gm[nr.x][nr.y]=='#')
                {
                    nr.x-=d[i];
                    nr.y-=d[3-i];
                    break;
                }
            }
            // blue part
            while(1)
            {
                nb.x+=d[i];
                nb.y+=d[3-i];
                if(gm[nb.x][nb.y]=='O') bf=true;
                else if(gm[nb.x][nb.y]=='#')
                {
                    nb.x-=d[i];
                    nb.y-=d[3-i];
                    break;
                }
            }
            // if part
            if(bf) continue;
            else if(rf)
            {
                ans=min(ans,step);
                continue;
            }
            if(nr==nb)
            {
                int rm=abs(r.x-nr.x)+abs(r.y-nr.y);
                int bm=abs(b.x-nb.x)+abs(b.y-nb.y);
                if(rm>bm)
                {
                    nr.x-=d[i];
                    nr.y-=d[3-i];
                }
                else
                {
                    nb.x-=d[i];
                    nb.y-=d[3-i];
                }
            }
            rq.push(nr);
            bq.push(nb);
            sq.push(step+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    pii rb,bb;
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>gm[i][j];
            if(gm[i][j]=='R')
            {
                rb={i,j};
                gm[i][j]='.';
            }
            else if(gm[i][j]=='B')
            {
                bb={i,j};
                gm[i][j]='.';
            }
        }
    }
    
    bfs(rb,bb);
    
    if(ans==IMAX) cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return 0;
}
