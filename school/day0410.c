#include <stdio.h>
#include <math.h>

int fibo(int n, int a1, int a2)
{
    // a3 = a1+a2;
    // a1 = a2;
    // a2 = a3;
    // ��� -> (n-2) �� �ݺ�
    // ���������� n�� �󸶰� �Ǹ� ���� -> �ݺ��� ������ n-1 ���
    // n == 2 �̸� a2 return
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

    return fibona(n-1) + fibona(n-2); // �ᱹ �Ȱ��� �� Ǯ�� ���� �� -> ��� Ǯ��Ἥ a1,a0 �θ� ��Ÿ����
    // a1,a0 ������ �Լ����� 0,1�� �����ϴϱ� ��!
}
int main(void)
{   
    // �Ǻ���ġ ����
    int n;
    printf("�Ǻ���ġ ������ n��° ���� ����غ���!\n");
    printf("���°���� ���Ұų�?:");
    scanf("%d",&n);
    printf("\n");
    int result1 = fibo(n,1,1);
    printf("%d\n",result1);

    int result2 = fibona(n);
    printf("%d\n",result2);
    return 0;
}