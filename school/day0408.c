#include <stdio.h>

// 팩토리얼 재귀함수 복습
int facto(int num)
{
    if (num == 0)
    return 1;
    else if ( num < 0)
    return -1;

    return num * facto(num-1);
}

int main(void)
{
    int num;
    printf("양의 정수 num 입력 :");
    scanf("%d",&num);
    int num_fac = facto(num);
    if (num_fac < 0)
    {
        printf("\n잘못된 접근\n");
        return 1;
    }
    printf("\n%d! = %d\n",num,num_fac);
    return 0;
}