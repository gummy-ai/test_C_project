#include <stdio.h>
#include <stdlib.h>

int divisors(int N)
{
    if ( N <= 0 )
    {
        printf("자연수를 입력해주세요:\n");
        return 0;
    }
    int sum = 1;
    for ( int i = 2; i<=N/2; i++ )
    {
        if ( N % i == 0)
        {
            sum = sum +i;
        }
    }
    return sum;
}

int main(void)
{
    while (1)
    {
        int num;
        printf("완전수인지 확인할 자연수:");
        printf("\n");
        scanf("%d",&num);

        int sum_result = divisors(num);
        if ( num == sum_result )
        {
            printf("%d는 완전수입니다.\n",num);
        }
        else
        {
            printf("%d을 제외한 약수합은 %d\n",num,sum_result);
        }

        int TF;
        printf("0을 입력하면 완전수 판별 종료:");
        scanf("%d",&TF);
        if ( TF == 0)
        break;
        printf("\n");
    }
    return 0;
}

// 실수 모음
// 1. 비교적 안전한 방식: null 고려해서 scanf("%9s",ch); 로
// 2. int 를 float로, %f 를 %d로 쓰는 안 좋은 습관
// 3. 삼항 연산자 뒤에 ? 써야함
// 4. 나누기랑 나머지 착각 주의 (/ 와 %)
// 5. case '~' : 이 순서로 써야한다

// 암기 할 것
// 1. scanf 에서만 double %lf 로
// 2. 실수 리터럴은 double 이므로 float 에 저장하려면 f를 뒤에 붙여야함. (자동 형변환이 안되기에)
// 2-1. float는 4바이트, double은 8바이트
// 2-2. 기본적으로 작은 자료형은 큰 자료형으로 자동 변환된다. 따라서 정수는 실수로 변환될 수 있다.
// 3. \" 는 "가 출력된다.
// 4. (조건) ? n:m true:false

// switch 문, do while 문 복습하기