#include <stdio.h>

int Add(int n1,int n2)
{
    return n1+n2;
}
int Subtract(int n1,int n2)
{
    return n1-n2;
}
int Multiply(int n1,int n2)
{
    return n1*n2;
}
int Divide(int n1,int n2)
{
    if ( n2 != 0)
    return n1/n2;
    else
    return 0;
}
int Showif(int n1,int n2,int (*ptr) (int,int))
{
    return ptr(n1,n2);
}
int main(void)
{
    int num1,num2,choice;
    printf("Enter two integers: ");
    scanf("%d %d",&num1,&num2);
    printf("\nSelect operation:");
    printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nChoice num: ");
    scanf("%d",&choice);
    getchar();
    printf("\n");
    
    int result;
    switch (choice)
    {
        case 1:
        printf("Result : %d",Showif(num1,num2,Add));
        break;
        case 2:
        printf("Result : %d",Showif(num1,num2,Subtract));
        break;
        case 3:
        printf("Result : %d",Showif(num1,num2,Multiply));
        break;
        case 4:
        if ( Showif(num1,num2,Divide) == 0)
        printf("Error: Division by zero is not allowed!\n");
        else
        printf("Result : %d",Showif(num1,num2,Divide));
        break;
        default :
        printf("Select 1 to 4 num");
    }

    return 0;
}
// c���� ��Ʈ�� �͸��Լ����� num1,num2 �����ϰ� ���¹� ����
// ������ ���� 0�� �� ���� �޼��� ��¹� : �׳� return 0�� ó���ϰ� if �Լ����� 0�̸� printf �ϴ� ������!
// �Լ��� �̸��� �ּ� : ���� �����ͷ� �޾ƾ��Ѵ�.