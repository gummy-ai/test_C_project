#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    //���μ����� ���α׷�
    int num; // 
    printf("���μ������� ���ڸ� �Է����ּ���:");
    scanf("%d",&num);
    printf("\n");

    //1. �켱 �Է��� �������� �Ҽ��� �迭�� ��������.
    int *prime_defore = malloc(sizeof(int)*num);
    int k = 0; // �迭 ����
    for (int i = 2; i<=num; i++)
    {
        int TF = 1;
        for (int j = 2; j<=sqrt(i); j++) // ���� ��
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
    // ���ο� �迭�� �����ϱ� (�޸� ����ȭ)
    int * prime_new = malloc(sizeof(int)*k);
    for (int i=0; i<k; i++)
    {
        prime_new[i] = prime_defore[i];
    }
    free(prime_defore);
    // ���μ����� ����
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
    // �˻�
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

// �Ǽ� ����
// 1. free�� �������� ��ġ�ؾ��Ѵ�.
// 2. sqrt num �� �ƴ϶� sqrt i
// 3. �ƹ� �۵��� ���ٸ� ���� �ɸ��°� ���� �ִ�.

// �˾Ƴ� ���
// 1. if (TF) �� �ǹ̴� TF = 1 �̸� ����
// 2. 