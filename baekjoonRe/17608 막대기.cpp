/*
변수 설정
 n: 막대기의 개수
 i: 반복할 때 쓸 것
 cnt: 보이는 막대기의 개수
 t: 지금까지 본 막대기 중 가장 높은 막대기의 높이
 h[100005]: 막대기들의 높이
*/

#include <iostream>
using namespace std;

int n, i, cnt, t, h[100005];

int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    
    for(i = n; i >= 1; i--)
    {
        if(h[i] > t)
        {
            cnt++;
            t=h[i];
        }
    }
    
    cout << cnt;
}
