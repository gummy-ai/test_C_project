#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// gcd ���
int gcd(int num1, int num2)
{
    int r = num1 % num2;
    if ( r == 0 )
    {
        return num2;
    }
    return gcd(num2,r);
}

// ���ڿ� ���� ���
void print_inverse_str(char *str,int index)
{
    if ( index < 0)
    {
        return;
    }
    printf("%c",str[index]);
    return print_inverse_str(str,index-1);
}

// �ŵ����� ���
int power(int a, int n)
{
    if (n == 0)
    return 1;
    return a * power(a,n-1);
}

// ��Ŭ���� Ȯ�� �˰���
int main(void)
{
    // int num1, num2;
    // printf("�ִ������� ���� �� �ڿ����� �Է����ּ���:");
    // scanf("%d %d",&num1,&num2);
    // getchar();
    // printf("\n");
    // int Y = gcd(num1,num2);
    // printf("%d �� %d �� �ִ�������: %d\n",num1,num2,Y);

    // char str[4] = "abc";
    // print_inverse_str(str,4-2);
    // printf("%d\n",power(2,7));
    return 0;
}