#include <stdio.h>

int main(void)
{
    char r[10] = "asffddd";
    printf("%s\n",r); // null 과 ?(쓰레기 값)은 다름
    scanf("%s",r);  //엔터까지만 덮어쓴다.
    printf("%s\n",r);
    printf("%c",r[3]); // 그래서 4번째 원소부터는 그대로 존재
    
    // 실수는 오차가 있음
    float f = 0; // 0.0 & 0 다 가능
    for (int i = 0; i<1000; i++)
    {
        f += 0.1;
    }
    // bit 단위 연산
    int num1, num2;
    num1 = 5; num2 = 3;
    printf("num1 & num2: %d",num1&num2); // AND
    // AND : 1,1 만 1, 나머지 0
    printf("num1 | num2: %d",num1|num2); // OR
    // OR : 0,0 만 0, 나머지 1
    printf("num1 ^ num2: %d",num1^num2); // XOR
    // 0,1 & 1,0 :1 이고 0,0 & 1,1 :0
    printf("num1 ^ num2: %d",~num1); // ~ , num1은 변화X, 반전 결과만
    printf("num1<<2: %d",num1<<2); // << , num1 변화X,왼쪽으로 두 칸 이동
    // 즉, 왼쪽 1칸 이동할 때마다 정수 값은 2배씩 증가
    printf("num1>>2: %d",num1>>2); // << , num1 변화X,오른쪽으로 두 칸 이동
    // 즉, 오른쪽 1칸 이동할 때마다 정수 값은 2배씩 감소
    // CPU에 따라 이동하고 나서 1 or 0이 채워질 수 있다.

    // 배열이름은 배열(메모리세트)를 가리키는 포인터 상수
    // %s 의 특징
    char arr[100];
    char *ptr;
    ptr = arr;
    scanf("%s",ptr);
    printf("%s\n",ptr);
    printf("%s",arr);
    return 0;
}