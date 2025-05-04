#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int num;
    printf("소인수분해할 숫자를 입력해주세요: ");
    scanf("%d", &num);
    if (num <= 1)
    {
        printf("2 이상의 자연수를 입력해주세요.\n");
        return 1;
    }

    // 소수 배열 생성
    int size = num / log(num) + 10; // 왜 안됨?
    int *primes = malloc(sizeof(int) * (size));
    int k = 0;
    primes[k++] = 2;
    for (int i = 3; i <= num; i+=2)
    {
        int is_prime = 1;
        for (int j = 3; j <= sqrt(i); j+=2)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
        primes[k++] = i;
    }

    // 소인수분해
    int *divisors = malloc(sizeof(int) * k);
    int seq = 0, temp = num;
    for (int i=0; i<k && temp >1; i++)
    {
        while ( temp % primes[i] == 0)
        {
            divisors[seq++] = primes[i];
            temp /= primes[i];
        }
    }

    // 출력
    printf("소인수분해 결과: ");
    int sum = 1;
    for (int i = 0; i < seq; i++)
    {
        printf("%d", divisors[i]);
        sum *= divisors[i];

        if (i < seq - 1)
        printf(" * ");
    }
    printf(" = %d\n", sum);

    free(primes);
    free(divisors);
    return 0;
}

// 실수 모음
// 1. & 가 아니라 &&