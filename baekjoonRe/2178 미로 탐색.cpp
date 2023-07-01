#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,visited[105][105];
char arr[105][105];
int df[4]={0,0,-1,1};
int ds[4]={-1,1,0,0};

void bfs(pair<int, int> s)
{
    queue<pair<int, int>> q;
    q.push(s);
    while (!q.empty()) {
        pair<int, int> h=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pair<int, int> a={h.first+df[i],h.second+ds[i]};
            if(0<=a.first&&0<=a.second&&a.first<n&&a.second<m&&arr[a.first][a.second]=='1'&&!visited[a.first][a.second])
            {
                q.push(a);
                visited[a.first][a.second]=visited[h.first][h.second]+1;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bfs({0,0});
    cout<<visited[n-1][m-1]+1;
    return 0;
}
