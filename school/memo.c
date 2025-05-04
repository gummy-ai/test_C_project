#include <stdio.h>
#include <stdlib.h>

int divisors(int N)
{
    if ( N <= 0 )
    {
        printf("�ڿ����� �Է����ּ���:\n");
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
        printf("���������� Ȯ���� �ڿ���:");
        printf("\n");
        scanf("%d",&num);

        int sum_result = divisors(num);
        if ( num == sum_result )
        {
            printf("%d�� �������Դϴ�.\n",num);
        }
        else
        {
            printf("%d�� ������ ������� %d\n",num,sum_result);
        }

        int TF;
        printf("0�� �Է��ϸ� ������ �Ǻ� ����:");
        scanf("%d",&TF);
        if ( TF == 0)
        break;
        printf("\n");
    }
    return 0;
}

// �Ǽ� ����
// 1. ���� ������ ���: null ����ؼ� scanf("%9s",ch); ��
// 2. int �� float��, %f �� %d�� ���� �� ���� ����
// 3. ���� ������ �ڿ� ? �����
// 4. ������� ������ ���� ���� (/ �� %)
// 5. case '~' : �� ������ ����Ѵ�

// �ϱ� �� ��
// 1. scanf ������ double %lf ��
// 2. �Ǽ� ���ͷ��� double �̹Ƿ� float �� �����Ϸ��� f�� �ڿ� �ٿ�����. (�ڵ� ����ȯ�� �ȵǱ⿡)
// 2-1. float�� 4����Ʈ, double�� 8����Ʈ
// 2-2. �⺻������ ���� �ڷ����� ū �ڷ������� �ڵ� ��ȯ�ȴ�. ���� ������ �Ǽ��� ��ȯ�� �� �ִ�.
// 3. \" �� "�� ��µȴ�.
// 4. (����) ? n:m true:false

// switch ��, do while �� �����ϱ�