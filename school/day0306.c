#include <stdio.h>

int main(void)
{
    char r[10] = "asffddd";
    printf("%s\n",r); // null �� ?(������ ��)�� �ٸ�
    scanf("%s",r);  //���ͱ����� �����.
    printf("%s\n",r);
    printf("%c",r[3]); // �׷��� 4��° ���Һ��ʹ� �״�� ����
    
    // �Ǽ��� ������ ����
    float f = 0; // 0.0 & 0 �� ����
    for (int i = 0; i<1000; i++)
    {
        f += 0.1;
    }
    // bit ���� ����
    int num1, num2;
    num1 = 5; num2 = 3;
    printf("num1 & num2: %d",num1&num2); // AND
    // AND : 1,1 �� 1, ������ 0
    printf("num1 | num2: %d",num1|num2); // OR
    // OR : 0,0 �� 0, ������ 1
    printf("num1 ^ num2: %d",num1^num2); // XOR
    // 0,1 & 1,0 :1 �̰� 0,0 & 1,1 :0
    printf("num1 ^ num2: %d",~num1); // ~ , num1�� ��ȭX, ���� �����
    printf("num1<<2: %d",num1<<2); // << , num1 ��ȭX,�������� �� ĭ �̵�
    // ��, ���� 1ĭ �̵��� ������ ���� ���� 2�辿 ����
    printf("num1>>2: %d",num1>>2); // << , num1 ��ȭX,���������� �� ĭ �̵�
    // ��, ������ 1ĭ �̵��� ������ ���� ���� 2�辿 ����
    // CPU�� ���� �̵��ϰ� ���� 1 or 0�� ä���� �� �ִ�.

    // �迭�̸��� �迭(�޸𸮼�Ʈ)�� ����Ű�� ������ ���
    // %s �� Ư¡
    char arr[100];
    char *ptr;
    ptr = arr;
    scanf("%s",ptr);
    printf("%s\n",ptr);
    printf("%s",arr);
    return 0;
}