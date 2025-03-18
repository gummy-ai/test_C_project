#include <stdio.h>

int main(void)
{
    // char ch1 = 7, ch2 = 5;
    // char result = ch1 + ch2;
    // printf("%d",sizeof(ch1 + ch2));
    // printf("%d",sizeof(result));
    // double rad;
    // double area;
    // printf("원의 반지름 입력 :\n");
    // scanf("%lf",&rad);
    // area = rad*rad*3.1415; // rad^2 왜 안됨?
    // printf("원의 넓이: %f\n",area);
    // int ch = 'A'; 가능!!
    // printf("%c",65); 가능!!

    // float rad1;
    // float area1;
    // printf("원의 반지름 입력 :\n");
    // scanf("%f",&rad1);
    // area1 = rad1*rad1*3.1415; // rad^2 왜 안됨?
    // printf("원의 넓이: %f\n",area1);
    // char ch1 = 'A', ch2 = 65;
    // printf("%c",ch1);
    // printf("%c",ch2);
    // int num;
    // char ch;

    // printf("숫자를 입력하세요: ");
    // scanf("%d", &num); // 숫자 입력

    // while (getchar() != '\n'); // 버퍼 비우기
    // // 조건문에 함수를 사용하는 것은 함수를 호출하고 그 반환값을 조건으로 사용하는 것.

    // printf("문자를 입력하세요: ");
    // ch = getchar(); // 문자 입력
    // getchar(); // 버퍼 비우기기
    // printf("%c",ch);

    int n1 =3, n2 = 4;
    double diresult;
    diresult = (double)n1/n2; // 3.0/4 -> 실수가 바이트 큼 따라서 실수 연산으로 바뀜 3.0/4.0 으로!
    printf("나눗셈 결과:%f",diresult); 
    return 0;
}