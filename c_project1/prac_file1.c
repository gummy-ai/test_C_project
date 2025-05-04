#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("info.txt","w");

    if (fp == NULL)
    {
        perror("file opening fail");
        return 1;
    }

    int input;
    printf("�̸��� ���̸� ������� �Է��ϼ���:");
    while ((input = getchar()) != '\n')
    {
        fputc(input,fp);
    }
    fputc('\n',fp);
    printf("\n");
    fclose(fp);

    FILE *fp2 = fopen("info.txt","r");

    if (fp2 == NULL)
    {
        perror("file opening fail");
        return 1;
    }

    int ch;
    while(1)
    {
        ch = fgetc(fp2);
        if (ch == EOF)
            break;
        printf("%c",ch);
    }
    fclose(fp2);

    return 0;
}

// 1. ��徵 �� ''���� ""���� �򰥸� - > "" �̴�
// 2. while((ch=getchar()) != \n) �� ����� ǥ���� ���� ������... -> ���� ���� ''������
// 3. NULL ��� �ϱ�
// 4. ������ ��Ծ ��� �� �� �� (1. fputc 2. fprintf)
// -> 4.1 fputc �ϰڴ� ch�� fp��Ʈ���� fputc(ch,fp) -> (getchar()�� ����)
// -> 4.2 �̰� �׳� fprintf(fp,"%s","text"); �̷��� ���� ��

/* �ǵ�� 1. �������� �ι��� �־ ���� �� Ȥ�� �� ���� ����
    while ((input = getchar()) != '\n')
    {
        fputc(input,fp);
    }
    fputc('\n',fp);
*/