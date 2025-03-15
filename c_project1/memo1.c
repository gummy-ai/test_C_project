#include <stdio.h>
#include <stdlib.h> // atoi(), atof() 사용을 위해 필요
#include <ctype.h>  // isdigit() 사용을 위해 필요
#include <string.h> // strlen() 사용을 위해 필요

#define SUBJECTS 5

int is_valid_number(const char *str) {
    // 빈 문자열이면 무효
    if (str[0] == '\0') return 0;

    int dot_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) return 0;  // 소수점이 1개 이상이면 무효
        } else if (!isdigit(str[i])) {
            return 0;  // 숫자가 아니면 무효
        }
    }
    return 1;
}

int main(void)
{
    int array[SUBJECTS] = {0};
    char input[100];  // 사용자 입력을 문자열로 받기 위한 버퍼

    printf("5과목의 점수를 각각 입력하세요 (0~100 사이의 정수):\n");

    for (int i = 0; i < SUBJECTS; i++)
    {
        while (1) {
            printf("%d 번째 과목 점수: ", i + 1);
            scanf("%s", input); // 문자열로 입력 받음
            
            if (!is_valid_number(input)) {
                printf("?? 0~100 사이의 정수를 입력하세요.\n");
                continue;
            }

            int answer = atoi(input); // 문자열을 정수로 변환

            if (answer < 0 || answer > 100) {
                printf("?? 0~100 사이의 정수를 입력하세요.\n");
                continue;
            }

            array[i] = answer;
            break; // 유효한 값 입력 시 루프 종료
        }
    }

    float sum = 0.0f;
    for (int i = 0; i < SUBJECTS; i++)
    {
        sum += array[i];
    }

    printf("총점은 %.2f 입니다.\n", sum);
    printf("평균은 %.2f 입니다.\n", sum / SUBJECTS);

    return 0;
}