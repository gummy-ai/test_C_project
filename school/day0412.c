#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// gcd 출력
int gcd(int num1, int num2)
{
    int r = num1 % num2;
    if ( r == 0 )
    {
        return num2;
    }
    return gcd(num2,r);
}

// 문자열 역순 출력
void print_inverse_str(char *str,int index)
{
    if ( index < 0)
    {
        return;
    }
    printf("%c",str[index]);
    return print_inverse_str(str,index-1);
}

// 거듭제곱 출력
int power(int a, int n)
{
    if (n == 0)
    return 1;
    return a * power(a,n-1);
}

// 유클리드 확장 알고리즘
int main(void)
{
    // int num1, num2;
    // printf("최대공약수를 구할 두 자연수를 입력해주세요:");
    // scanf("%d %d",&num1,&num2);
    // getchar();
    // printf("\n");
    // int Y = gcd(num1,num2);
    // printf("%d 와 %d 의 최대공약수는: %d\n",num1,num2,Y);

    // char str[4] = "abc";
    // print_inverse_str(str,4-2);
    // printf("%d\n",power(2,7));
    return 0;
}