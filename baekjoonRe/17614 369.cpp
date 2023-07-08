/*
변수 설정
 i: 반복할 때 쓸 것
 n: 입력하는 숫자
 cnt: 박수를 친 횟수
 tmp: 3, 6, 9의 개수를 셀 때 쓸 것
*/

#include <iostream>
using namespace std;

int i, n, cnt, tmp;

int main()
{
    cin >> n;
    for(i = 3; i <= n; i++)
    {
        tmp = i;
        while(tmp)
        {
            if(tmp % 10 == 3 || tmp % 10 == 6 || tmp % 10 == 9)
            {
                cnt++;
            }
            tmp /= 10;
        }
    }
    cout << cnt;
    return 0;
}
