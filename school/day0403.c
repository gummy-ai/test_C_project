#include <stdio.h>
#include <math.h>

int main(void)
{
    // sqrt 의 수치 구현??

    /*int num1 = 5;
    printf("%f",sqrt(5));*/

    // 소수 출력을 해보자 -> for 문과 if 문으로 출력하자.
    int arr[569];
    int j = 0;
    for (int i=2; i<570; i++)
    {
        int TF = 1;
        int test_num = 2;
        while (test_num < sqrt(i))
        {
            // 만약 나누면  ~소수 나눈다? 나머지 = 0 -> i % test_num == 0
            if ( i % test_num == 0)
            {
                TF = 0;
                break; // 이거는 반복문 하나만 나가는 역할
            }
            test_num++;
        }
        if (TF == 0)
        {
            continue;
        }
        arr[j] = i;
        j++;
    }
    for (int i = 0; i<j; i++)
    {
        printf("%d",arr[i]);
        if (i == j-1)
        {
            break;
        }
        printf(",");
    }
}

// 까먹은 문법들 모음
/* 1. ~=가 아니라 !=
2. 보통 0은 거짓, 1은 참
3. for 안에 j를 쓰면 밖에서는 j를 인식 못 함
 */