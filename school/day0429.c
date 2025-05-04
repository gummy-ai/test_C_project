#include <stdio.h>

int main(void)
{
    // // 주소 ++ -- 같이 쓰거나 따로 쓸 때 결과 예상 연습해보기
    // int *ptr;
    // int arr[5] = {1,2,3,4,5};
    // ptr = arr;
    // // 예를들어 밑에 ++ 이 어디서 적용될지..
    // printf("ptr++ = %p, ptr = %p, arr[0] 주소: %p\n",++ptr,ptr,arr);
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int arr[3] = {num1,num2,num3};
    int * ptr1 = arr;
    int * ptr2 = arr;
    printf("%d %d\n",*ptr1,*ptr1+1);
    printf("%d %d\n",*ptr1,*(ptr1+1));
    // ptr1++; // 주소를 증가시킴
    printf("%d\n",*ptr1++);
    // 다음에 주소를 1 증가시킴
    printf("%d\n",*ptr1);
    printf("%d %d %d\n",*ptr2++,*ptr2,*ptr2); // 10 10 10
    printf("%d %d %d\n",*ptr2++,*ptr2,*ptr2); // 20 20 20
    return 0;
}