/*
변수 설정
    n: 참가 인원 수
    k: 한 방에 배정할 수 있는 최대 인원 수
    s: 성별
    y: 학년
    ot: 1, 2학년
    tf[2]: 3, 4학년
    fs[2]: 5, 6학년
    ans: 총 사용 방 개수
    i: 반복할 때 쓸 것
*/

#include <iostream>
using namespace std;

int n, k, s, y, ot, tf[2], fs[2], ans, i;

int main()
{
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> s >> y;
        if(y == 1 || y == 2)
        {
            ot++;
        }
        else if(y == 3 || y == 4)
        {
            tf[s]++;
        }
        else
        {
            fs[s]++;
        }
    }
    ans += ot / k;
    
    if(ot % k != 0)
    {
        ans++;
    }
    
    for(i = 0; i < 2; i++)
    {
        ans += tf[i] / k;
        if(tf[i] % k != 0)
        {
            ans++;
        }
        ans += fs[i] / k;
        if(fs[i] % k != 0)
        {
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}
