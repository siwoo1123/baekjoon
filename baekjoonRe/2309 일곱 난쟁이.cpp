/*
변수 설정
    t[10]: 아홉 난쟁이들의 키
    i, j: 반복을 위한 변수
    s: 가짜 난쟁이의 키의 합
    tmp: 정렬의 위한 변수
    flag: 처리를 위한 반복이 끝났는가?
*/

#include <iostream>
using namespace std;

int t[10], i, s, j, tmp;
bool flag;

int main()
{
    for(i = 1; i <= 9; i++)
    {
        cin >> t[i];
        s += t[i];
    }

    s-= 100;

    for(i = 1; i <= 8; i++)
    {
        for(j = i + 1; j <= 9; j++)
        {
            if(t[i] + t[j] == s)
            {
                t[i] = 9999;
                t[j] = 9999;
                flag = true;
                break;
            }
            if(flag == true)
            {
                break;
            }
        }
    }
    for(i = 1; i <= 8; i++)
    {
        for(j = i+1; j <= 9; j++)
        {
            if(t[i] > t[j])
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
    
    for(i = 1; i <= 7; i++)
    {
        cout << t[i] << "\n";
    }
    return 0;
}
