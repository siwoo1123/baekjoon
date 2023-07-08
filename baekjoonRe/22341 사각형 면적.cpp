/*
변수 설정
    n: 세로, 가로의 길이
    c: 점의 개수
    x: 세로
    y: 가로
    a: 현재의 세로
    b: 현재의 가로
    i: 1부터 C까지 1씩 증가 하는 변수
    ga: 가로 넓이
    se: 세로 넓이
*/

#include <iostream>
using namespace std;

int n, c, x, y, a, b, i, ga, se;

int main()
{
    cin >> n >> c;
    
    a = n;
    b = n;
    
    for(i = 1; i <= c; i++)
    {
        cin >> x >> y;
        if(a > x && b > y)
        {
            ga = x * b;
            se = y * a;
            
            if(ga >= se)
            {
                a = x;
            }
            else
            {
                b = y;
            }
        }
    }
    
    cout << a * b;
    return 0;
}
