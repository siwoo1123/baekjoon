/*
변수 설정
    k: 한 방당 최대 배정 가능 인원수
    n: 전체 학생 수
    s: 성별
    y: 학년
    r[7][2]: 각 학년의 각 성별을 가진 인원수
    ans: 최종 인원 쑤
    i, j: 반복할 때 쓸 것
*/

#include <iostream>
using namespace std;

int k, n, s, y, r[7][2], ans, i, j;

int main()
{
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> s >> y;
        r[y][s]++;
    }
    for(i = 1; i <= 6; i++)
    {
        for(j = 0; j <= 1; j++)
        {
            if(r[i][j])
            {
                ans += r[i][j]/k;
                if(r[i][j] % k)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
