#include <stdio.h>

int main(void)
{
    // char ch1 = 7, ch2 = 5;
    // char result = ch1 + ch2;
    // printf("%d",sizeof(ch1 + ch2));
    // printf("%d",sizeof(result));
    // double rad;
    // double area;
    // printf("���� ������ �Է� :\n");
    // scanf("%lf",&rad);
    // area = rad*rad*3.1415; // rad^2 �� �ȵ�?
    // printf("���� ����: %f\n",area);
    // int ch = 'A'; ����!!
    // printf("%c",65); ����!!

    // float rad1;
    // float area1;
    // printf("���� ������ �Է� :\n");
    // scanf("%f",&rad1);
    // area1 = rad1*rad1*3.1415; // rad^2 �� �ȵ�?
    // printf("���� ����: %f\n",area1);
    // char ch1 = 'A', ch2 = 65;
    // printf("%c",ch1);
    // printf("%c",ch2);
    // int num;
    // char ch;

    // printf("���ڸ� �Է��ϼ���: ");
    // scanf("%d", &num); // ���� �Է�

    // while (getchar() != '\n'); // ���� ����
    // // ���ǹ��� �Լ��� ����ϴ� ���� �Լ��� ȣ���ϰ� �� ��ȯ���� �������� ����ϴ� ��.

    // printf("���ڸ� �Է��ϼ���: ");
    // ch = getchar(); // ���� �Է�
    // getchar(); // ���� �����
    // printf("%c",ch);

    int n1 =3, n2 = 4;
    double diresult;
    diresult = (double)n1/n2; // 3.0/4 -> �Ǽ��� ����Ʈ ŭ ���� �Ǽ� �������� �ٲ� 3.0/4.0 ����!
    printf("������ ���:%f",diresult); 
    return 0;
}