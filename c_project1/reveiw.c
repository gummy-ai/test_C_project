#include <stdio.h>

int main() {
    int num1, num2;
    printf("좋아하는 숫자 두 개를 입력해봐: ");
    scanf("%d %d", &num1, &num2);
    printf("합계: %d\n", num1 + num2);
    return 0;
}