#include <stdio.h>

void print_file_func(FILE *fp)
{
    char ch;
    while ((ch=fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
}
int check_file_func(FILE *fp)
{
    if ( fp == NULL )
    {
        perror("file open fail");
        return 1;
    }
    else
        return 0;
}
int main(void)
{
    FILE *fp = fopen("out.txt","r");
    if ( fp == NULL )
    {
        perror("file open fail");
        return 1;
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF )
    {
        printf("%c",ch);
    }
    fclose(fp);

    FILE *fp2 = fopen("out.txt","a");
    if ( fp2 == NULL )
    {
        perror("file open fail");
        return 1;
    }
    fprintf(fp2,"%s\n","\n프로그래밍내에서 내가 쓴 내용을 미리 넣을 수 있다.");
    printf("하지만 이렇게 사용자의 입력을 받아서 넣을 수도 있다.\n");
    while( (ch = getchar()) != '\n' )
    {
        fputc(ch,fp2);
    }
    fputc('\n',fp2);
    fclose(fp2);
    FILE *fp3 = fopen("out.txt","r");
    if ( fp3 == NULL )
    {
        perror("file open fail");
        return 1;
    }
    while ((ch=fgetc(fp3)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp3);
    FILE * fp4 = fopen("out.txt","a");
    check_file_func(fp4);
    fprintf(fp4,"%s\n","사라질까 안사라질까?");
    fclose(fp4);
    FILE *fp5 = fopen("out.txt","r");
    print_file_func(fp5);
    fclose(fp5);
    return 0;
}