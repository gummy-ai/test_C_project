#include <stdio.h>
#include <stdlib.h> // atoi(), atof() ����� ���� �ʿ�
#include <ctype.h>  // isdigit() ����� ���� �ʿ�
#include <string.h> // strlen() ����� ���� �ʿ�

#define SUBJECTS 5

int is_valid_number(const char *str) {
    // �� ���ڿ��̸� ��ȿ
    if (str[0] == '\0') return 0;

    int dot_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) return 0;  // �Ҽ����� 1�� �̻��̸� ��ȿ
        } else if (!isdigit(str[i])) {
            return 0;  // ���ڰ� �ƴϸ� ��ȿ
        }
    }
    return 1;
}

int main(void)
{
    int array[SUBJECTS] = {0};
    char input[100];  // ����� �Է��� ���ڿ��� �ޱ� ���� ����

    printf("5������ ������ ���� �Է��ϼ��� (0~100 ������ ����):\n");

    for (int i = 0; i < SUBJECTS; i++)
    {
        while (1) {
            printf("%d ��° ���� ����: ", i + 1);
            scanf("%s", input); // ���ڿ��� �Է� ����
            
            if (!is_valid_number(input)) {
                printf("?? 0~100 ������ ������ �Է��ϼ���.\n");
                continue;
            }

            int answer = atoi(input); // ���ڿ��� ������ ��ȯ

            if (answer < 0 || answer > 100) {
                printf("?? 0~100 ������ ������ �Է��ϼ���.\n");
                continue;
            }

            array[i] = answer;
            break; // ��ȿ�� �� �Է� �� ���� ����
        }
    }

    float sum = 0.0f;
    for (int i = 0; i < SUBJECTS; i++)
    {
        sum += array[i];
    }

    printf("������ %.2f �Դϴ�.\n", sum);
    printf("����� %.2f �Դϴ�.\n", sum / SUBJECTS);

    return 0;
}