#include <stdio.h>

int main(void)
{
    // // �ּ� ++ -- ���� ���ų� ���� �� �� ��� ���� �����غ���
    // int *ptr;
    // int arr[5] = {1,2,3,4,5};
    // ptr = arr;
    // // ������� �ؿ� ++ �� ��� �������..
    // printf("ptr++ = %p, ptr = %p, arr[0] �ּ�: %p\n",++ptr,ptr,arr);
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int arr[3] = {num1,num2,num3};
    int * ptr1 = arr;
    int * ptr2 = arr;
    printf("%d %d\n",*ptr1,*ptr1+1);
    printf("%d %d\n",*ptr1,*(ptr1+1));
    // ptr1++; // �ּҸ� ������Ŵ
    printf("%d\n",*ptr1++);
    // ������ �ּҸ� 1 ������Ŵ
    printf("%d\n",*ptr1);
    printf("%d %d %d\n",*ptr2++,*ptr2,*ptr2); // 10 10 10
    printf("%d %d %d\n",*ptr2++,*ptr2,*ptr2); // 20 20 20
    return 0;
}