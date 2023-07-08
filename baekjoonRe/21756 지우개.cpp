/*
변수 설정
    n: 입력받는 수 N이자 배열의 길이
    arr[102]: 처리할 때 쓸 배열
    i: 반복할 때 쓸 변수
    brr[102]: B단계 작업을 위해 쓸 배열
    ai: arr의 index
    nb: n백업
*/

#include <iostream>
using namespace std;

int n, arr[102], i, brr[102], ai, nb;

int main()
{
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    while(n > 1)
    {
        nb = n;
        for(i = 2; i <= nb; i += 2)
        {
            brr[i] = arr[i];
        }
        n /= 2;
        ai = 1;

        for(i = 1; i <= nb; i++)
        {
            arr[i] = 0;
        }

        for(i = 1; i <= nb; i++)
        {
            if(brr[i] != 0)
            {
                arr[ai] = brr[i];
                ai++;
            }
        }
        for(i = 1; i <= nb; i++)
        {
            brr[i] = 0;
        }
    }
    cout << arr[1];

    return 0;
}
