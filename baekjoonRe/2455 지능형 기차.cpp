/*
변수 설정
 a: 열차에 탄 사람
 b: 열차에서 내린 사람
 mx: 기차에 사람이 가장 많이 탔을 때의 사람 수
 i: 반복할 때 사용하는 것
 tmp: 한 역을 출발했을 때 열차에 있는 사람 수
*/

#include <iostream>
using namespace std;

int a, b, i, mx, tmp;

int main()
{
    for(i = 0; i < 4; i++)
    {
        cin >> b >> a;
        tmp = tmp-b+a;
        if(tmp > mx)
        {
            mx = tmp;
        }
    }
    cout << mx;
}
