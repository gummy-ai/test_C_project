#include <stdio.h>

// ���丮�� ����Լ� ����
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
    printf("���� ���� num �Է� :");
    scanf("%d",&num);
    int num_fac = facto(num);
    if (num_fac < 0)
    {
        printf("\n�߸��� ����\n");
        return 1;
    }
    printf("\n%d! = %d\n",num,num_fac);
    return 0;
}