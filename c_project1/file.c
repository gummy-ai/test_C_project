#include <stdio.h>

#define MAX 10000
int main(void)
{
    // ���� �����
    // ���Ͽ� � �����͸� ����
    // ���Ͽ� ����� ������ �ҷ�����

    // fputs, fgets
    char line[MAX]; //char line[10000];
    // ���Ͽ� ����
    FILE * file = fopen("c:\\test1.txt","rb"); // r w a ���� �б�,����,���ص�(�̾��)
    // t b �ؽ�Ʈ,���̳ʸ� �����͸� �ǹ�
    if (file == NULL)
    {
        printf("���� ���� ����\n");
        return 1;
    }
    // fputs("fputs �� �̿��ؼ� ���� ����Կ�:\n",file);
    // fputs("�� �������� Ȯ�����ּ���\n",file);

    while (fgets(line,MAX,file) != NULL)
    {
        printf("%s",line);
    }
    // fclose(file);

    // fprintf fscanf
    int num[6] = {0};
    int bonus = 0;
    char str1[MAX];
    char str2[MAX];
    FILE * file = fopen("c:\\test2.txt","wb");
    if (file==NULL)
    {
        printf("���� ���� ����\n");
    }
    fprintf(file,"%s %d %d %d %d %d %d\n","��÷ ��ȣ",1,2,3,4,5,6);
    fprintf(file,"%s %d\n","���ʽ���ȣ",7);

    fclose(file);
    return 0;
}