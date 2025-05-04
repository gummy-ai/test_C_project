#include <stdio.h>
#include <math.h>

int fibo(int n, int a1, int a2)
{
    // a3 = a1+a2;
    // a1 = a2;
    // a2 = a3;
    // 재귀 -> (n-2) 번 반복
    // 종료조건은 n이 얼마가 되면 종료 -> 반복할 때마다 n-1 재귀
    // n == 2 이면 a2 return
    if (n == 1)
    return a1;
    else if ( n== 2)
    return a2;

    return fibo(n-1,a2,a1+a2);
}

int fibona(int n)
{
    if (n == 0)
    return 0;
    if ( n== 1)
    return 1;

    return fibona(n-1) + fibona(n-2); // 결국 똑같은 값 풀어 써준 것 -> 계속 풀어써서 a1,a0 로만 나타내고
    // a1,a0 에서의 함숫값이 0,1을 리턴하니까 끝!
}
int main(void)
{   
    // 피보나치 수열
    int n;
    printf("피보나치 수열의 n번째 항을 출력해보자!\n");
    printf("몇번째항을 구할거냐?:");
    scanf("%d",&n);
    printf("\n");
    int result1 = fibo(n,1,1);
    printf("%d\n",result1);

    int result2 = fibona(n);
    printf("%d\n",result2);
    return 0;
}