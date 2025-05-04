#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    //소인수분해 프로그램
    int num; // 
    printf("소인수분해할 숫자를 입력해주세요:");
    scanf("%d",&num);
    printf("\n");

    //1. 우선 입력한 수까지의 소수를 배열에 저장하자.
    int *prime_defore = malloc(sizeof(int)*num);
    int k = 0; // 배열 순서
    for (int i = 2; i<=num; i++)
    {
        int TF = 1;
        for (int j = 2; j<=sqrt(i); j++) // 나눌 수
        {
            if ( i % j == 0)
            {
                TF = 0;
                break;
            }
        }
        if (TF)
        {
        prime_defore[k++] = i;
        }
    }
    // 새로운 배열에 적용하기 (메모리 최적화)
    int * prime_new = malloc(sizeof(int)*k);
    for (int i=0; i<k; i++)
    {
        prime_new[i] = prime_defore[i];
    }
    free(prime_defore);
    // 소인수분해 시작
    int * divisors = malloc(sizeof(int)*k);
    int seq = 0;
    for (int i=0 ; i<k; i++)
    {
        if ( num % prime_new[i] == 0)
        {
            divisors[seq] = prime_new[i];
            seq++;
            num = num / prime_new[i];
            if ( num == 1)
            {break;}
            i = -1;
        }
    }
    free(prime_new);
    for (int i=0; i<seq; i++)
    {
        printf("%d ",divisors[i]);
    }
    printf("\n");
    // 검산
    int sum = 1;
    for (int i=0; i<seq; i++)
    {
        printf("%d",divisors[i]);
        sum = sum*divisors[i];
        if (i == seq -1)
        {
            printf("=");
            break;
        }
        printf("*");
    }
    printf("%d\n",sum);
    free(divisors);
    return 0;
}

// 실수 모음
// 1. free는 마지막에 위치해야한다.
// 2. sqrt num 이 아니라 sqrt i
// 3. 아무 작동이 없다면 오래 걸리는걸 수도 있다.

// 알아낸 사실
// 1. if (TF) 의 의미는 TF = 1 이면 실행
// 2. 